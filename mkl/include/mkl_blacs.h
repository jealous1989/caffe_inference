/*******************************************************************************
* Copyright 1999-2016 Intel Corporation All Rights Reserved.
*
* The source code,  information  and material  ("Material") contained  herein is
* owned by Intel Corporation or its  suppliers or licensors,  and  title to such
* Material remains with Intel  Corporation or its  suppliers or  licensors.  The
* Material  contains  proprietary  information  of  Intel or  its suppliers  and
* licensors.  The Material is protected by  worldwide copyright  laws and treaty
* provisions.  No part  of  the  Material   may  be  used,  copied,  reproduced,
* modified, published,  uploaded, posted, transmitted,  distributed or disclosed
* in any way without Intel's prior express written permission.  No license under
* any patent,  copyright or other  intellectual property rights  in the Material
* is granted to  or  conferred  upon  you,  either   expressly,  by implication,
* inducement,  estoppel  or  otherwise.  Any  license   under such  intellectual
* property rights must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing,  you may not remove or alter this
* notice or  any  other  notice   embedded  in  Materials  by  Intel  or Intel's
* suppliers or licensors in any way.
*******************************************************************************/

/*
!  Content:
!      Intel(R) Math Kernel Library (MKL) interface for BLACS routines
!******************************************************************************/

#ifndef _MKL_BLACS_H_
#define _MKL_BLACS_H_

#include "mkl_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* <name>_ declarations */

void	igamx2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	sgamx2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	dgamx2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	cgamx2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	zgamx2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);

void	igamn2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	sgamn2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	dgamn2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	cgamn2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);
void	zgamn2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, MKL_INT *rA, MKL_INT *cA, const MKL_INT *ldia, const MKL_INT *rdest, const MKL_INT *cdest);

void	igsum2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	sgsum2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	dgsum2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	cgsum2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	zgsum2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);

void	igesd2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	sgesd2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	dgesd2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	cgesd2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	zgesd2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);

void	itrsd2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const MKL_INT *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	strsd2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const float *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	dtrsd2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const double *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	ctrsd2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const float *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);
void	ztrsd2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const double *A, const MKL_INT *lda, const MKL_INT *rdest, const MKL_INT *cdest);

void	igerv2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	sgerv2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	dgerv2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	cgerv2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	zgerv2d_(const MKL_INT *ConTxt, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);

void	itrrv2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	strrv2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	dtrrv2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	ctrrv2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	ztrrv2d_(const MKL_INT *ConTxt, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);

void	igebs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, const MKL_INT *A, const MKL_INT *lda);
void	sgebs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, const float *A, const MKL_INT *lda);
void	dgebs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, const double *A, const MKL_INT *lda);
void	cgebs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, const float *A, const MKL_INT *lda);
void	zgebs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, const double *A, const MKL_INT *lda);

void	itrbs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const MKL_INT *A, const MKL_INT *lda);
void	strbs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const float *A, const MKL_INT *lda);
void	dtrbs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const double *A, const MKL_INT *lda);
void	ctrbs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const float *A, const MKL_INT *lda);
void	ztrbs2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, const double *A, const MKL_INT *lda);

void	igebr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	sgebr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	dgebr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	cgebr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	zgebr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);

void	itrbr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, MKL_INT *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	strbr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	dtrbr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	ctrbr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, float *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);
void	ztrbr2d_(const MKL_INT *ConTxt, const char *scope, const char *top, const char *uplo, const char *diag, const MKL_INT *m, const MKL_INT *n, double *A, const MKL_INT *lda, const MKL_INT *rsrc, const MKL_INT *csrc);

void	blacs_pinfo_(MKL_INT *mypnum, MKL_INT *nprocs);
void	blacs_setup_(MKL_INT *mypnum, MKL_INT *nprocs);
void	blacs_get_(const MKL_INT *ConTxt, const MKL_INT *what, MKL_INT *val);
void	blacs_set_(const MKL_INT *ConTxt, const MKL_INT *what, const MKL_INT *val);
void	blacs_gridinit_(MKL_INT *ConTxt, const char *layout, const MKL_INT *nprow, const MKL_INT *npcol);
void	blacs_gridmap_(MKL_INT *ConTxt, const MKL_INT *usermap, const MKL_INT *ldup, const MKL_INT *nprow0, const MKL_INT *npcol0);

void	blacs_freebuff_(const MKL_INT *ConTxt, const MKL_INT *Wait);
void	blacs_gridexit_(const MKL_INT *ConTxt);
void	blacs_abort_(const MKL_INT *ConTxt, const MKL_INT *ErrNo);
void	blacs_exit_(const MKL_INT *notDone);

void	blacs_gridinfo_(const MKL_INT *ConTxt, MKL_INT *nprow, MKL_INT *npcol, MKL_INT *myrow, MKL_INT *mycol);
MKL_INT	blacs_pnum_(const MKL_INT *ConTxt, const MKL_INT *prow, const MKL_INT *pcol);
void	blacs_pcoord_(const MKL_INT *ConTxt, const MKL_INT *nodenum, MKL_INT *prow, MKL_INT *pcol);

void	blacs_barrier_(const MKL_INT *ConTxt, const char *scope);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MKL_BLACS_H_ */
