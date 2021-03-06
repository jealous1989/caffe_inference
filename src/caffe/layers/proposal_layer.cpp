// ------------------------------------------------------------------
// Licensed under The MIT License [see fast-rcnn/LICENSE for details]
//
// \author         Shaohua WAN
// \email          shaohuawan@gmail.com
// \date           Nov 2015
// 
// ------------------------------------------------------------------

#include <cfloat>

#include "caffe/layers/proposal_layer.hpp"

namespace caffe {

template <typename Dtype>
void ProposalLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  ProposalParameter proposal_param = this->layer_param_.proposal_param();
  CHECK_GT(proposal_param.feat_stride(), 0)
      << "feat_stride must be > 0";
  _feat_stride = proposal_param.feat_stride();
  
  CHECK_GT(proposal_param.base_size(), 0)
      << "base_size must be > 0";
  int base_size = proposal_param.base_size();
  
  CHECK_GT(proposal_param.ratios_size(), 0)
      << "ratios size must be > 0";
  int num_ratios = proposal_param.ratios_size();
   
  CHECK_GT(proposal_param.scales_size(), 0)
      << "scales size must be > 0";
  int num_scales = proposal_param.scales_size();
  
  rpn_pre_nms_topN  = proposal_param.rpn_pre_nms_topn();
  rpn_post_nms_topN = proposal_param.rpn_post_nms_topn();
  rpn_nms_thresh    = proposal_param.rpn_nms_thresh();
  rpn_min_size      = proposal_param.rpn_min_size();
  LOG(INFO) << "rpn_pre_nms_topN: " << rpn_pre_nms_topN;
  LOG(INFO) << "rpn_post_nms_topN: " << rpn_post_nms_topN;
  LOG(INFO) << "rpn_nms_thresh: " << rpn_nms_thresh;
  LOG(INFO) << "rpn_min_size: " << rpn_min_size;
  LOG(INFO) << "feat_stride: " << _feat_stride;
  LOG(INFO) << "base_size: " << base_size;

  

  //int base_size = 16;
  std::vector<Dtype> ratios;
  for(int i=0; i < num_ratios; i++)
      ratios.push_back(proposal_param.ratios(i));
  //ratios[0] = 0.5; 
  //ratios[1] = 1.0; 
  //ratios[2] = 2.0; 
  std::vector<Dtype> scales;
  for(int i=0; i < num_scales; i++)
      scales.push_back(proposal_param.scales(i));
  //scales[0] = 4 ;
  //scales[1] = 8 ;
  //scales[2] = 16;
  //scales[3] = 32;
  _anchors = generate_anchors<Dtype>( base_size, ratios, scales );
  _num_anchors = _anchors.size();

  std::vector<int> shape(2);
  shape[0] = 1;
  shape[1] = 5;
  top[0]->Reshape(shape);
  if( top.size() > 1 )
     top[1]->Reshape(1, 1, 1, 1);
}

template <typename Dtype>
void ProposalLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
}

template <typename Dtype>
void ProposalLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {

  //int rpn_pre_nms_topN  = RPN_PRE_NMS_TOP_N;
  //int rpn_post_nms_topN = RPN_POST_NMS_TOP_N;
  //Dtype rpn_nms_thresh    = RPN_NMS_THRESH;
  //int rpn_min_size      = RPN_MIN_SIZE;
  
  // the first set of _num_anchors channels are bg probs
  // the second set are the fg probs, which we want
  Blob<Dtype>* scores = bottom[0];
  Blob<Dtype>* bbox_deltas = bottom[1];
  Blob<Dtype>* im_info = bottom[2];

  // 1. Generate proposals from bbox deltas and shifted anchors
  int height = scores->height();
  int width  = scores->width();

  // Enumerate all shifts
  std::vector<int> shift_x(width), shift_y(height);
  for(int i=0; i<width; i++)
    shift_x[i] = i*_feat_stride;
  for(int j=0; j<height; j++)
    shift_y[j] = j*_feat_stride;

  // Enumerate all shifted anchors:
  //
  // add A anchors (1, A, 4) to
  // cell K shifts (K, 1, 4) to get
  // shift anchors (K, A, 4)
  // reshape to (K*A, 4) shifted anchors
  int A = _num_anchors;
  //int K = width*height;
  std::vector<Box<Dtype> > anchors;
  for(int j=0; j<height; j++)
     for(int k=0; k<width; k++)
       for(int i=0; i<A; i++)
       {
         Box<Dtype> box( _anchors[i], shift_x[k], shift_y[j] ) ;
         anchors.push_back(box);
       }

  std::vector<Dtype> scores_;
  int n=scores->num();
  int c=scores->channels();
  int h=scores->height();
  int w=scores->width();
  for(int i=0; i<n; i++)
    for(int k=0; k<h; k++)
      for(int l=0; l<w; l++)
        for(int j=c/2; j<c; j++)
          scores_.push_back( scores->cpu_data()[ scores->offset(i,j,k,l) ] );
  
  // Convert anchors into proposals via bbox transformations
  std::vector<Box<Dtype> > proposals = bbox_transform_inv(anchors, bbox_deltas);

  // 2. clip predicted boxes to image
  Dtype im_scale = im_info->cpu_data()[im_info->offset(0,2)];
  clip_boxes(proposals, im_info->cpu_data()[im_info->offset(0,0)], 
             im_info->cpu_data()[im_info->offset(0,1)] );

  // 3. remove predicted boxes with either height or width < threshold
  // (NOTE: convert rpn_min_size to input image scale stored in im_info[2])
  std::vector<int> keep_ind = _filter_boxes(proposals, rpn_min_size * im_scale );
  proposals = keep( proposals, keep_ind );
  scores_   = keep( scores_,   keep_ind );

  // 4. sort all (proposal, score) pairs by score from highest to lowest
  // 5. take top rpn_pre_nms_topN (e.g. 6000)
  std::vector<int> ind = sort_ind( scores_, false );
  if( rpn_pre_nms_topN > 0 )
    ind.resize( std::min( (int)ind.size(), rpn_pre_nms_topN ) );

  proposals = keep( proposals, ind );
  scores_   = keep( scores_,   ind );

  // 6. apply nms (e.g. threshold = 0.7)
  // 7. take after_nms_topN (e.g. 300)
  // 8. return the top proposals (-> RoIs top)
  keep_ind = nms<Dtype>(proposals, scores_, rpn_nms_thresh);

  if( rpn_post_nms_topN > 0 )
    keep_ind.resize( std::min( rpn_post_nms_topN, (int)keep_ind.size() ) );

  proposals = keep( proposals, keep_ind );
  scores_   = keep( scores_,   keep_ind );
  
  // Output rois blob
  // Our RPN implementation only supports a single input image, so all
  // batch inds are 0
  std::vector<int> top_shape(2);
  top_shape[0] = proposals.size();
  top_shape[1] = 4+1;
  top[0]->Reshape(top_shape);
  
  for(int i=0; i<top_shape[0]; i++)
  {
    top[0]->mutable_cpu_data()[ top[0]->offset(i,0) ] = 0; 
    top[0]->mutable_cpu_data()[ top[0]->offset(i,1) ] = proposals[i].x1;
    top[0]->mutable_cpu_data()[ top[0]->offset(i,2) ] = proposals[i].y1;
    top[0]->mutable_cpu_data()[ top[0]->offset(i,3) ] = proposals[i].x2;
    top[0]->mutable_cpu_data()[ top[0]->offset(i,4) ] = proposals[i].y2;
  }
}

template <typename Dtype>
void ProposalLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
  NOT_IMPLEMENTED;
}


#ifdef CPU_ONLY
STUB_GPU(ProposalLayer);
#endif

INSTANTIATE_CLASS(ProposalLayer);
REGISTER_LAYER_CLASS(Proposal);


}  // namespace caffe
