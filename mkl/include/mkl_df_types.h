/* file: mkl_df_types.h */
/*******************************************************************************
* Copyright 2006-2016 Intel Corporation All Rights Reserved.
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
//++
//  This file contains user-level type definitions.
//--
*/

#ifndef __MKL_DF_TYPES_H__
#define __MKL_DF_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mkl_types.h"

/*
//++
//  TYPEDEFS
//--
*/

/*
//  POINTER TO DATA FITTING STRUCTURE
//  This is a void pointer to hide implementation details.
*/
typedef void* DFTaskPtr;

/*
//  DATA FITTING CALLBACK FOR SUPPORT OF USER-DEFINED INTERPOLATION AND
//  EXTRAPOLATION
*/
typedef int (*dfsInterpCallBack) ( MKL_INT64* n, MKL_INT64 cell[], float  site[], float  r[], void* param );
typedef int (*dfdInterpCallBack) ( MKL_INT64* n, MKL_INT64 cell[], double site[], double r[], void* param );

/*
//  DATA FITTING CALLBACK FOR SUPPORT OF USER-DEFINED INTEGRATION
*/
typedef int (*dfsIntegrCallBack) ( MKL_INT64* n, MKL_INT64 lcell[], float  llim[], MKL_INT64 rcell[], float  rlim[], float  r[], void* params );
typedef int (*dfdIntegrCallBack) ( MKL_INT64* n, MKL_INT64 lcell[], double llim[], MKL_INT64 rcell[], double rlim[], double r[], void* params );

/*
//  DATA FITTING CALLBACK FOR SUPPORT OF USER-DEFINED CELL SEARCH
*/
typedef int (*dfsSearchCellsCallBack) ( MKL_INT64* n, float  site[], MKL_INT64 cell[], int flag[], void* params );
typedef int (*dfdSearchCellsCallBack) ( MKL_INT64* n, double site[], MKL_INT64 cell[], int flag[], void* params );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MKL_DF_TYPES_H__ */
