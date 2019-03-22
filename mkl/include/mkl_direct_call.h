/*******************************************************************************
* Copyright 2014-2016 Intel Corporation All Rights Reserved.
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
!      Intel(R) Math Kernel Library (MKL) C/C++ macros for MKL_DIRECT_CALL
!******************************************************************************/
#ifndef _MKL_DIRECT_CALL_H
#define _MKL_DIRECT_CALL_H

#include "mkl_types.h"

#if defined(MKL_DIRECT_CALL_SEQ) && !defined(MKL_DIRECT_CALL)
    #define MKL_DIRECT_CALL
#endif

#ifdef MKL_DIRECT_CALL_SEQ
#define MKL_DIRECT_CALL_INIT_FLAG MKL_INT mkl_direct_call_flag = 1
#else
#define MKL_DIRECT_CALL_INIT_FLAG MKL_INT mkl_direct_call_flag = 0
#endif

#ifdef MKL_DIRECT_CALL

#ifdef __cplusplus
extern "C" {
#endif

/* Function declerations for the direct calls */
#if defined(MKL_STDCALL)
void __stdcall dgemm_direct(const char *transa, int transa_len, const char *transb, int transb_len, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,const double *alpha, const double *a, const MKL_INT *lda, const double *b, const MKL_INT *ldb,const double *beta, double *c, const MKL_INT *ldc, const MKL_INT* flag);
void __stdcall sgemm_direct(const char *transa, int transa_len, const char *transb, int transb_len, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const float *a, const MKL_INT *lda, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc, const MKL_INT* flag);
void __stdcall cgemm_direct(const char *transa, int transa_len, const char *transb, int transb_len, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT* flag);
void __stdcall zgemm_direct(const char *transa, int transa_len, const char *transb, int transb_len, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT* flag);

void __stdcall cgemm3m_direct(const char *transa, int transa_len, const char *transb, int transb_len, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT* flag);
void __stdcall zgemm3m_direct(const char *transa, int transa_len, const char *transb, int transb_len, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT* flag);

void __stdcall dtrsm_direct(const char *side, int side_len, const char *uplo, int uplo_len, const char *transa, int transa_len, const char *diag, int diag_len, const MKL_INT *m, const MKL_INT *n, const double *alpha, const double *a, const MKL_INT *lda, double *b, const MKL_INT *ldb, const MKL_INT* flag);
void __stdcall strsm_direct(const char *side, int side_len, const char *uplo, int uplo_len, const char *transa, int transa_len, const char *diag, int diag_len, const MKL_INT *m, const MKL_INT *n, const float *alpha, const float *a, const MKL_INT *lda, float *b, const MKL_INT *ldb, const MKL_INT* flag);
void __stdcall ctrsm_direct(const char *side, int side_len, const char *uplo, int uplo_len, const char *transa, int transa_len, const char *diag, int diag_len, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, MKL_Complex8 *b, const MKL_INT *ldb, const MKL_INT* flag);
void __stdcall ztrsm_direct(const char *side, int side_len, const char *uplo, int uplo_len, const char *transa, int transa_len, const char *diag, int diag_len, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, MKL_Complex16 *b, const MKL_INT *ldb, const MKL_INT* flag);

void __stdcall dsyrk_direct(const char *uplo, int uplo_len, const char *trans, int trans_len, const MKL_INT *n, const MKL_INT *k,const double *alpha, const double *a, const MKL_INT *lda, const double *beta, double *c, const MKL_INT *ldc, const MKL_INT* flag);
void __stdcall ssyrk_direct(const char *uplo, int uplo_len, const char *trans, int trans_len, const MKL_INT *n, const MKL_INT *k, const float *alpha, const float *a, const MKL_INT *lda, const float *beta, float *c, const MKL_INT *ldc, const MKL_INT* flag);
void __stdcall csyrk_direct(const char *uplo, int uplo_len, const char *trans, int trans_len, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT* flag);
void __stdcall zsyrk_direct(const char *uplo, int uplo_len, const char *trans, int trans_len, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT* flag);

void __stdcall daxpy_direct(const MKL_INT *n, const double *alpha, const double *x, const MKL_INT *incx, double *y, const MKL_INT *incy, const MKL_INT* flag);
void __stdcall saxpy_direct(const MKL_INT *n, const float *alpha, const float *x, const MKL_INT *incx, float *y, const MKL_INT *incy, const MKL_INT* flag);
void __stdcall caxpy_direct(const MKL_INT *n, const MKL_Complex8 *alpha, const MKL_Complex8 *x, const MKL_INT *incx, MKL_Complex8 *y, const MKL_INT *incy, const MKL_INT* flag);
void __stdcall zaxpy_direct(const MKL_INT *n, const MKL_Complex16 *alpha, const MKL_Complex16 *x, const MKL_INT *incx, MKL_Complex16 *y, const MKL_INT *incy, const MKL_INT* flag);

double __stdcall ddot_direct(const MKL_INT *n, const double *x, const MKL_INT *incx, const double *y, const MKL_INT *incy);
float  __stdcall sdot_direct(const MKL_INT *n, const float *x, const MKL_INT *incx, const float *y, const MKL_INT *incy);

#else
void dgemm_direct(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,const double *alpha, const double *a, const MKL_INT *lda, const double *b, const MKL_INT *ldb,const double *beta, double *c, const MKL_INT *ldc, const MKL_INT* flag);
void sgemm_direct(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const float *a, const MKL_INT *lda, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc, const MKL_INT* flag);
void cgemm_direct(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT* flag);
void zgemm_direct(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT* flag);

void cgemm3m_direct(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT* flag);
void zgemm3m_direct(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT* flag);

void dtrsm_direct(const char *side, const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *n, const double *alpha, const double *a, const MKL_INT *lda, double *b, const MKL_INT *ldb, const MKL_INT* flag);
void strsm_direct(const char *side, const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *n, const float *alpha, const float *a, const MKL_INT *lda, float *b, const MKL_INT *ldb, const MKL_INT* flag);
void ctrsm_direct(const char *side, const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, MKL_Complex8 *b, const MKL_INT *ldb, const MKL_INT* flag);
void ztrsm_direct(const char *side, const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, MKL_Complex16 *b, const MKL_INT *ldb, const MKL_INT* flag);

void dsyrk_direct(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k,const double *alpha, const double *a, const MKL_INT *lda, const double *beta, double *c, const MKL_INT *ldc, const MKL_INT* flag);
void ssyrk_direct(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k, const float *alpha, const float *a, const MKL_INT *lda, const float *beta, float *c, const MKL_INT *ldc, const MKL_INT* flag);
void csyrk_direct(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT* flag);
void zsyrk_direct(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT* flag);


void daxpy_direct(const MKL_INT *n, const double *alpha, const double *x, const MKL_INT *incx, double *y, const MKL_INT *incy, const MKL_INT* flag);
void saxpy_direct(const MKL_INT *n, const float *alpha, const float *x, const MKL_INT *incx, float *y, const MKL_INT *incy, const MKL_INT* flag);
void caxpy_direct(const MKL_INT *n, const MKL_Complex8 *alpha, const MKL_Complex8 *x, const MKL_INT *incx, MKL_Complex8 *y, const MKL_INT *inc, const MKL_INT* flag);
void zaxpy_direct(const MKL_INT *n, const MKL_Complex16 *alpha, const MKL_Complex16 *x, const MKL_INT *incx, MKL_Complex16 *y, const MKL_INT *incy, const MKL_INT* flag);

double ddot_direct(const MKL_INT *n, const double *x, const MKL_INT *incx, const double *y, const MKL_INT *incy);
float  sdot_direct(const MKL_INT *n, const float *x, const MKL_INT *incx, const float *y, const MKL_INT *incy);
#endif

#ifdef __INTEL_COMPILER
#define MKL_DC_USE_C 1
#else
#define MKL_DC_USE_C 0
#endif

#if (MKL_DC_USE_C == 1)

#undef MKL_DOUBLE
#undef MKL_SINGLE
#undef MKL_COMPLEX16
#undef MKL_COMPLEX
#define MKL_DOUBLE
#include "mkl_direct_blas.h"

#undef MKL_DOUBLE
#undef MKL_SINGLE
#undef MKL_COMPLEX16
#undef MKL_COMPLEX
#define MKL_SINGLE
#include "mkl_direct_blas.h"

#undef MKL_DOUBLE
#undef MKL_SINGLE
#undef MKL_COMPLEX16
#undef MKL_COMPLEX
#define MKL_COMPLEX
#include "mkl_direct_blas.h"

#undef MKL_DOUBLE
#undef MKL_SINGLE
#undef MKL_COMPLEX16
#undef MKL_COMPLEX
#define MKL_COMPLEX16
#include "mkl_direct_blas.h"

#else

#define mkl_dc_dgemm(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) 0
#define mkl_dc_sgemm(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) 0
#define mkl_dc_cgemm(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) 0
#define mkl_dc_zgemm(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) 0

#define mkl_dc_dtrsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) 0
#define mkl_dc_strsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) 0
#define mkl_dc_ctrsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) 0
#define mkl_dc_ztrsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) 0

#define mkl_dc_dsyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) 0
#define mkl_dc_ssyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) 0
#define mkl_dc_csyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) 0
#define mkl_dc_zsyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) 0

#define mkl_dc_ddot(n, x, incx, y, incy) 0
#define mkl_dc_sdot(n, x, incx, y, incy) 0

#define mkl_dc_daxpy(n, alpha, x, incx, y, incy) 0
#define mkl_dc_saxpy(n, alpha, x, incx, y, incy) 0
#define mkl_dc_caxpy(n, alpha, x, incx, y, incy) 0
#define mkl_dc_zaxpy(n, alpha, x, incx, y, incy) 0

#endif

#if defined(__linux__) || (__INTEL_COMPILER >= 1500)
#define MKL_DIRECT_CALL_CONSTANT_P(m,n,k) (__builtin_constant_p(*(m)) && __builtin_constant_p(*(n)) && __builtin_constant_p(*(k)))
#else
#define MKL_DIRECT_CALL_CONSTANT_P(m,n,k) (0)
#endif

#define MKL_DC_CBLAS_CHECKSIZE(m,n,k) ((((m) <= 5 && (n) <= 5 && (k) <= 5)) && MKL_DC_USE_C)
#define MKL_DC_CHECKSIZE(m,n,k) (((*(m) <= 5 && *(n) <= 5 && *(k) <= 5)) && MKL_DC_USE_C)
#define MKL_DC_GEMM3M_CHECKSIZE(m,n,k) (((*(m) <= 4 && *(n) <= 4 && *(k) <= 4)) && MKL_DC_USE_C)
#define MKL_DC_CBLAS_SYRK_CHECKSIZE(n,k) ((((n) <= 3 && (k) <= 9)) && MKL_DC_USE_C)
#define MKL_DC_SYRK_CHECKSIZE(n,k) (((*(n) <= 3 && *(k) <= 9)) && MKL_DC_USE_C)
#define MKL_DC_CBLAS_TRSM_CHECKSIZE(m,n) ((((m) <= 7 && (n) <= 7)) && MKL_DC_USE_C)
#define MKL_DC_TRSM_CHECKSIZE(m,n) (((*(m) <= 7 && *(n) <= 7)) && MKL_DC_USE_C)
#define MKL_DC_DAXPY_CHECKSIZE(n) ((*(n) <= 32) && MKL_DC_USE_C)
#define MKL_DC_SAXPY_CHECKSIZE(n) ((*(n) <= 64) && MKL_DC_USE_C)
#define MKL_DC_CAXPY_CHECKSIZE(n) ((*(n) <= 16) && MKL_DC_USE_C)
#define MKL_DC_ZAXPY_CHECKSIZE(n) ((*(n) <= 4 ) && MKL_DC_USE_C)
#define MKL_DC_DDOT_CHECKSIZE(n)  ((*(n) <= 32) && MKL_DC_USE_C)
#define MKL_DC_SDOT_CHECKSIZE(n)  ((*(n) <= 64) && MKL_DC_USE_C)

/* CBLAS interfaces */

/* CBLAS GEMM */
#if defined(MKL_STDCALL)
#define MKL_DC_CBLAS_GEMM_CONVERT(layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    \
    char *ftrans[]   = { "N", "T", "C"};\
    \
    MKL_INT index_transa, index_transb;\
    index_transa = (transa) - CblasNoTrans;\
    index_transb = (transb) - CblasNoTrans;\
    \
    if (layout == CblasRowMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transb], ftrans[index_transa],\
                    &(n), &(m), &(k), &(alpha),\
                    (b), &(ldb), (a), &(lda), &(beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transb], 1, ftrans[index_transa], 1,\
                    &(n), &(m), &(k), &(alpha),\
                    (b), &(ldb), (a), &(lda), &(beta), (c), &(ldc), &mkl_direct_call_flag);\
        } \
    }\
    else if (layout == CblasColMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transa], ftrans[index_transb],\
                    &(m), &(n), &(k), &(alpha),\
                    (a), &(lda), (b), &(ldb), &(beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transa], 1, ftrans[index_transb], 1,\
                    &(m), &(n), &(k), &(alpha),\
                    (a), &(lda), (b), &(ldb), &(beta), (c), &(ldc), &mkl_direct_call_flag);\
        }\
    }\
} while (0)

#define MKL_DC_CBLAS_COMPLEX_GEMM_CONVERT(layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    \
    char *ftrans[]   = { "N", "T", "C"};\
    \
    MKL_INT index_transa, index_transb;\
    index_transa = (transa) - CblasNoTrans;\
    index_transb = (transb) - CblasNoTrans;\
    \
    if (layout == CblasRowMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transb], ftrans[index_transa],\
                    &(n), &(m), &(k), (alpha),\
                    (b), &(ldb), (a), &(lda), (beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transb], 1, ftrans[index_transa], 1,\
                    &(n), &(m), &(k), (alpha),\
                    (b), &(ldb), (a), &(lda), (beta), (c), &(ldc), &mkl_direct_call_flag);\
        }\
    }\
    else if (layout == CblasColMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transa], ftrans[index_transb],\
                    &(m), &(n), &(k), (alpha),\
                    (a), &(lda), (b), &(ldb), (beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transa], 1, ftrans[index_transb], 1,\
                    &(m), &(n), &(k), (alpha),\
                    (a), &(lda), (b), &(ldb), (beta), (c), &(ldc), &mkl_direct_call_flag);\
        }\
    }\
} while (0)

#else
#define MKL_DC_CBLAS_GEMM_CONVERT(layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    \
    char *ftrans[]   = { "N", "T", "C"};\
    \
    MKL_INT index_transa, index_transb;\
    index_transa = (transa) - CblasNoTrans;\
    index_transb = (transb) - CblasNoTrans;\
    \
    if (layout == CblasRowMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transb], ftrans[index_transa],\
                    &(n), &(m), &(k), &(alpha),\
                    (b), &(ldb), (a), &(lda), &(beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transb], ftrans[index_transa],\
                    &(n), &(m), &(k), &(alpha),\
                    (b), &(ldb), (a), &(lda), &(beta), (c), &(ldc), &mkl_direct_call_flag);\
        } \
    }\
    else if (layout == CblasColMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transa], ftrans[index_transb],\
                    &(m), &(n), &(k), &(alpha),\
                    (a), &(lda), (b), &(ldb), &(beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transa], ftrans[index_transb],\
                    &(m), &(n), &(k), &(alpha),\
                    (a), &(lda), (b), &(ldb), &(beta), (c), &(ldc), &mkl_direct_call_flag);\
        }\
    }\
} while (0)

#define MKL_DC_CBLAS_COMPLEX_GEMM_CONVERT(layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    \
    char *ftrans[]   = { "N", "T", "C"};\
    \
    MKL_INT index_transa, index_transb;\
    index_transa = (transa) - CblasNoTrans;\
    index_transb = (transb) - CblasNoTrans;\
    \
    if (layout == CblasRowMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transb], ftrans[index_transa],\
                    &(n), &(m), &(k), (alpha),\
                    (b), &(ldb), (a), &(lda), (beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transb], ftrans[index_transa],\
                    &(n), &(m), &(k), (alpha),\
                    (b), &(ldb), (a), &(lda), (beta), (c), &(ldc), &mkl_direct_call_flag);\
        }\
    }\
    else if (layout == CblasColMajor) {\
        if (MKL_DC_CBLAS_CHECKSIZE(m,n,k)) { \
            fname_unrolledc(ftrans[index_transa], ftrans[index_transb],\
                    &(m), &(n), &(k), (alpha),\
                    (a), &(lda), (b), &(ldb), (beta), (c), &(ldc));\
        } else { \
            fname_direct(ftrans[index_transa], ftrans[index_transb],\
                    &(m), &(n), &(k), (alpha),\
                    (a), &(lda), (b), &(ldb), (beta), (c), &(ldc), &mkl_direct_call_flag);\
        }\
    }\
} while (0)

#endif

#define cblas_dgemm(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) MKL_DC_CBLAS_GEMM_CONVERT(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, mkl_dc_dgemm, dgemm_direct)
#define cblas_sgemm(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) MKL_DC_CBLAS_GEMM_CONVERT(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, mkl_dc_sgemm, sgemm_direct)
#define cblas_zgemm(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) MKL_DC_CBLAS_COMPLEX_GEMM_CONVERT(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, mkl_dc_zgemm, zgemm_direct)
#define cblas_cgemm(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) MKL_DC_CBLAS_COMPLEX_GEMM_CONVERT(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, mkl_dc_cgemm, cgemm_direct)

#define cblas_zgemm3m(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) MKL_DC_CBLAS_COMPLEX_GEMM_CONVERT(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, mkl_dc_zgemm, zgemm3m_direct)
#define cblas_cgemm3m(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc) MKL_DC_CBLAS_COMPLEX_GEMM_CONVERT(layout, ta, tb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc, mkl_dc_cgemm, cgemm3m_direct)

/* CBLAS TRSM */
#if defined(MKL_STDCALL)
#define MKL_DC_CBLAS_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fside[]    = {"L", "R"};\
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T", "C"};\
    char *fdiag[]    = {"N", "U"};\
    MKL_INT index_uplo, index_trans, index_diag, index_side; \
    index_side = side - CblasLeft; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    index_diag = diag - CblasNonUnit; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[1-index_side], fuplo[1-index_uplo], ftrans[index_trans], fdiag[index_diag], &(n), &(m), &(alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[1-index_side], 1, fuplo[1-index_uplo], 1, ftrans[index_trans], 1, fdiag[index_diag], 1, &(n), &(m), &(alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[index_side], fuplo[index_uplo], ftrans[index_trans], fdiag[index_diag], &(m), &(n), &(alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[index_side], 1, fuplo[index_uplo], 1, ftrans[index_trans], 1, fdiag[index_diag], 1, &(m), &(n), &(alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#define MKL_DC_CBLAS_COMPLEX_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fside[]    = {"L", "R"};\
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T", "C"};\
    char *fdiag[]    = {"N", "U"};\
    MKL_INT index_uplo, index_trans, index_diag, index_side; \
    index_side = side - CblasLeft; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    index_diag = diag - CblasNonUnit; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[1-index_side], fuplo[1-index_uplo], ftrans[index_trans], fdiag[index_diag], &(n), &(m), (alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[1-index_side], 1, fuplo[1-index_uplo], 1, ftrans[index_trans], 1, fdiag[index_diag], 1, &(n), &(m), (alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[index_side], fuplo[index_uplo], ftrans[index_trans], fdiag[index_diag], &(m), &(n), (alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[index_side], 1, fuplo[index_uplo], 1, ftrans[index_trans], 1, fdiag[index_diag], 1, &(m), &(n), (alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#else
#define MKL_DC_CBLAS_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fside[]    = {"L", "R"};\
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T", "C"};\
    char *fdiag[]    = {"N", "U"};\
    MKL_INT index_uplo, index_trans, index_diag, index_side; \
    index_side = side - CblasLeft; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    index_diag = diag - CblasNonUnit; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[1-index_side], fuplo[1-index_uplo], ftrans[index_trans], fdiag[index_diag], &(n), &(m), &(alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[1-index_side], fuplo[1-index_uplo], ftrans[index_trans], fdiag[index_diag], &(n), &(m), &(alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[index_side], fuplo[index_uplo], ftrans[index_trans], fdiag[index_diag], &(m), &(n), &(alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[index_side], fuplo[index_uplo], ftrans[index_trans], fdiag[index_diag], &(m), &(n), &(alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#define MKL_DC_CBLAS_COMPLEX_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fside[]    = {"L", "R"};\
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T", "C"};\
    char *fdiag[]    = {"N", "U"};\
    MKL_INT index_uplo, index_trans, index_diag, index_side; \
    index_side = side - CblasLeft; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    index_diag = diag - CblasNonUnit; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[1-index_side], fuplo[1-index_uplo], ftrans[index_trans], fdiag[index_diag], &(n), &(m), (alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[1-index_side], fuplo[1-index_uplo], ftrans[index_trans], fdiag[index_diag], &(n), &(m), (alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_TRSM_CHECKSIZE(m, n) ) { \
            fname_unrolledc(fside[index_side], fuplo[index_uplo], ftrans[index_trans], fdiag[index_diag], &(m), &(n), (alpha), (a), &(lda), (b), &(ldb)); \
        } else { \
            fname_direct(fside[index_side], fuplo[index_uplo], ftrans[index_trans], fdiag[index_diag], &(m), &(n), (alpha), (a), &(lda), (b), &(ldb), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#endif

#define cblas_dtrsm(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_CBLAS_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_dtrsm, dtrsm_direct)
#define cblas_strsm(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_CBLAS_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_strsm, strsm_direct)
#define cblas_ctrsm(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_CBLAS_COMPLEX_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ctrsm, ctrsm_direct)
#define cblas_ztrsm(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_CBLAS_COMPLEX_TRSM_CONVERT(layout, side, uplo, trans, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ztrsm, ztrsm_direct)

/* CBLAS SYRK */
#if defined(MKL_STDCALL)
#define MKL_DC_CBLAS_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T"};\
    MKL_INT index_uplo, index_trans; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[1-index_uplo], ftrans[1-index_trans], &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[1-index_uplo], 1, ftrans[1-index_trans], 1, &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[index_uplo], ftrans[index_trans], &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[index_uplo], 1, ftrans[index_trans], 1, &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#define MKL_DC_CBLAS_COMPLEX_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T"};\
    MKL_INT index_uplo, index_trans; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[1-index_uplo], ftrans[1-index_trans], &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[1-index_uplo], 1, ftrans[1-index_trans], 1, &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[index_uplo], ftrans[index_trans], &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[index_uplo], 1, ftrans[index_trans], 1, &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#else
#define MKL_DC_CBLAS_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T"};\
    MKL_INT index_uplo, index_trans; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[1-index_uplo], ftrans[1-index_trans], &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[1-index_uplo], ftrans[1-index_trans], &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[index_uplo], ftrans[index_trans], &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[index_uplo], ftrans[index_trans], &(n), &(k), &(alpha), (a), &(lda), &(beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#define MKL_DC_CBLAS_COMPLEX_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, fname_unrolledc, fname_direct)  do { \
    MKL_DIRECT_CALL_INIT_FLAG; \
    char *fuplo[]    = {"U", "L"};\
    char *ftrans[]   = {"N", "T"};\
    MKL_INT index_uplo, index_trans; \
    index_uplo = uplo - CblasUpper; \
    index_trans = trans - CblasNoTrans; \
    if (layout == CblasRowMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[1-index_uplo], ftrans[1-index_trans], &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[1-index_uplo], ftrans[1-index_trans], &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } else if (layout == CblasColMajor) { \
        if ( MKL_DC_CBLAS_SYRK_CHECKSIZE(n, k) ) { \
            fname_unrolledc(fuplo[index_uplo], ftrans[index_trans], &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc)); \
        } else { \
            fname_direct(fuplo[index_uplo], ftrans[index_trans], &(n), &(k), (alpha), (a), &(lda), (beta), (c), &(ldc), &mkl_direct_call_flag); \
        } \
    } \
} while (0)

#endif

#define cblas_dsyrk(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_CBLAS_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, mkl_dc_dsyrk, dsyrk_direct)
#define cblas_ssyrk(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_CBLAS_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, mkl_dc_ssyrk, ssyrk_direct)
#define cblas_csyrk(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_CBLAS_COMPLEX_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, mkl_dc_csyrk, csyrk_direct)
#define cblas_zsyrk(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_CBLAS_COMPLEX_SYRK_CONVERT(layout, uplo, trans, n, k, alpha, a, lda, beta, c, ldc, mkl_dc_zsyrk, zsyrk_direct)


/* CBLAS AXPY */
#define cblas_daxpy(n,a,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(&(n),&(a),x,&(incx),y,&(incy),MKL_DC_DAXPY_CHECKSIZE,mkl_dc_daxpy,daxpy_direct)
#define cblas_saxpy(n,a,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(&(n),&(a),x,&(incx),y,&(incy),MKL_DC_SAXPY_CHECKSIZE,mkl_dc_saxpy,saxpy_direct)
#define cblas_caxpy(n,a,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(&(n),a,x,&(incx),y,&(incy),MKL_DC_CAXPY_CHECKSIZE,mkl_dc_caxpy,caxpy_direct)
#define cblas_zaxpy(n,a,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(&(n),a,x,&(incx),y,&(incy),MKL_DC_ZAXPY_CHECKSIZE,mkl_dc_zaxpy,zaxpy_direct)

/* CBLAS DOT */
#define cblas_ddot(n,x,incx,y,incy)  mkl_dc_ddot_convert(&(n),x,&(incx),y,&(incy))
#define cblas_sdot(n,x,incx,y,incy)  mkl_dc_sdot_convert(&(n),x,&(incx),y,&(incy))

/* end of CBLAS interfaces */

/* DGEMM */
#define GEMM_DIRECT_FUNCTION 
#if defined(MKL_STDCALL)

#define MKL_DC_DGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_dgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        dgemm_direct((transa), sa, (transb), sb, (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define dgemm(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_DGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define dgemm_(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_DGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define DGEMM(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_DGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#else

#define MKL_DC_DGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_dgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        dgemm_direct((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define dgemm(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_DGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define dgemm_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_DGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define DGEMM(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_DGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#endif

/* SGEMM */
#if defined(MKL_STDCALL)

#define MKL_DC_SGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_sgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        sgemm_direct((transa), sa, (transb), sb, (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define sgemm(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_SGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define sgemm_(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_SGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define SGEMM(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_SGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#else

#define MKL_DC_SGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_sgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        sgemm_direct((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define sgemm(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_SGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define sgemm_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_SGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define SGEMM(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_SGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#endif

/* CGEMM */
#if defined(MKL_STDCALL)

#define MKL_DC_CGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_cgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        cgemm_direct((transa), sa, (transb), sb, (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define cgemm(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define cgemm_(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_CGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define CGEMM(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#else

#define MKL_DC_CGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_cgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        cgemm_direct((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define cgemm(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define cgemm_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_CGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define CGEMM(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#endif

/* ZGEMM */
#if defined(MKL_STDCALL)

#define MKL_DC_ZGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_zgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        zgemm_direct((transa), sa, (transb), sb, (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define zgemm(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define zgemm_(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_ZGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define ZGEMM(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#else

#define MKL_DC_ZGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_CHECKSIZE(m,n,k)) { \
        mkl_dc_zgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        zgemm_direct((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define zgemm(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define zgemm_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_ZGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define ZGEMM(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#endif

/* CGEMM3M */
#if defined(MKL_STDCALL)

#define MKL_DC_CGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_GEMM3M_CHECKSIZE(m,n,k)) { \
        mkl_dc_cgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        cgemm3m_direct((transa), sa, (transb), sb, (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    }\
} while (0)

#define cgemm3m(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define cgemm3m_(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_CGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define CGEMM3M(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#else

#define MKL_DC_CGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_GEMM3M_CHECKSIZE(m,n,k)) { \
        mkl_dc_cgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        cgemm3m_direct((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    }\
} while (0)

#define cgemm3m(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define cgemm3m_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_CGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define CGEMM3M(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_CGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#endif

/* ZGEMM3M */
#if defined(MKL_STDCALL)

#define MKL_DC_ZGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_GEMM3M_CHECKSIZE(m,n,k)) { \
        mkl_dc_zgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        zgemm3m_direct((transa), sa, (transb), sb, (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    }\
} while (0)

#define zgemm3m(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define zgemm3m_(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_ZGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define ZGEMM3M(transa,sa,transb,sb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM3M_CONVERT(transa, sa, transb, sb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#else

#define MKL_DC_ZGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)  do { \
    if (MKL_DC_GEMM3M_CHECKSIZE(m,n,k)) { \
        mkl_dc_zgemm((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        zgemm3m_direct((transa), (transb), (m), (n), (k), (alpha), (a), (lda), (b), (ldb), (beta), (c), (ldc), &mkl_direct_call_flag); \
    }\
} while (0)

#define zgemm3m(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define zgemm3m_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc) MKL_DC_ZGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
#define ZGEMM3M(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)  MKL_DC_ZGEMM3M_CONVERT(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)

#endif


/* ?TRSM_DIRECT */
#if defined(MKL_STDCALL)
#define MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, fname_unrolledc, fname_direct)  do { \
    if (MKL_DC_TRSM_CHECKSIZE(m,n)) { \
        fname_unrolledc((side), (uplo), (transa), (diag), (m), (n), (alpha), (a), (lda), (b), (ldb)); \
    } else { \
        MKL_DIRECT_CALL_INIT_FLAG; \
        fname_direct((side), (side_len), (uplo), (uplo_len), (transa), (transa_len), (diag), (diag_len), (m), (n), (alpha), (a), (lda), (b), (ldb), &mkl_direct_call_flag); \
    } \
} while (0)
#else
#define MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, fname_unrolledc, fname_direct)  do { \
    if (MKL_DC_TRSM_CHECKSIZE(m,n)) { \
        fname_unrolledc((side), (uplo), (transa), (diag), (m), (n), (alpha), (a), (lda), (b), (ldb)); \
    } else { \
        MKL_DIRECT_CALL_INIT_FLAG; \
        fname_direct((side), (uplo), (transa), (diag), (m), (n), (alpha), (a), (lda), (b), (ldb), &mkl_direct_call_flag); \
    } \
} while (0)
#endif

/* DTRSM_DIRECT */
#if defined(MKL_STDCALL)
#define dtrsm(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_dtrsm, dtrsm_direct)
#define dtrsm_(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_dtrsm, dtrsm_direct)
#define DTRSM(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_dtrsm, dtrsm_direct)

#else
#define dtrsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_dtrsm, dtrsm_direct)
#define dtrsm_(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_dtrsm, dtrsm_direct)
#define DTRSM(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_dtrsm, dtrsm_direct)

#endif

/* STRSM_DIRECT */
#if defined(MKL_STDCALL)
#define strsm(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_strsm, strsm_direct)
#define strsm_(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_strsm, strsm_direct)
#define STRSM(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_strsm, strsm_direct)

#else
#define strsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_strsm, strsm_direct)
#define strsm_(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_strsm, strsm_direct)
#define STRSM(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_strsm, strsm_direct)

#endif

/* CTRSM_DIRECT */
#if defined(MKL_STDCALL)
#define ctrsm(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_ctrsm, ctrsm_direct)
#define ctrsm_(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_ctrsm, ctrsm_direct)
#define CTRSM(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_ctrsm, ctrsm_direct)

#else
#define ctrsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ctrsm, ctrsm_direct)
#define ctrsm_(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ctrsm, ctrsm_direct)
#define CTRSM(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ctrsm, ctrsm_direct)

#endif

/* ZTRSM_DIRECT */
#if defined(MKL_STDCALL)
#define ztrsm(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_ztrsm, ztrsm_direct)
#define ztrsm_(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_ztrsm, ztrsm_direct)
#define ZTRSM(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, side_len, uplo, uplo_len, transa, transa_len, diag, diag_len, m, n, alpha, a, lda, b, ldb, mkl_dc_ztrsm, ztrsm_direct)

#else
#define ztrsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ztrsm, ztrsm_direct)
#define ztrsm_(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ztrsm, ztrsm_direct)
#define ZTRSM(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb)  MKL_DC_TRSM_CONVERT(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb, mkl_dc_ztrsm, ztrsm_direct)

#endif


/* ?SYRK_DIRECT */
/* DSYRK_DIRECT */
#if defined(MKL_STDCALL)

#define MKL_DC_DSYRK_CONVERT(uplo, su, trans, st, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_dsyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        dsyrk_direct((uplo), su, (trans), st, (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define dsyrk(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_DSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define dsyrk_(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_DSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define DSYRK(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_DSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)

#else

#define MKL_DC_DSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_dsyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        dsyrk_direct((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define dsyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_DSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define dsyrk_(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_DSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define DSYRK(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_DSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)

#endif

/* SSYRK_DIRECT */
#if defined(MKL_STDCALL)

#define MKL_DC_SSYRK_CONVERT(uplo, su, trans, st, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_ssyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        ssyrk_direct((uplo), su, (trans), st, (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define ssyrk(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_SSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define ssyrk_(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_SSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define SSYRK(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_SSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)

#else

#define MKL_DC_SSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_ssyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        ssyrk_direct((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define ssyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_SSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define ssyrk_(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_SSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define SSYRK(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_SSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)

#endif

/* ZSYRK_DIRECT */
#if defined(MKL_STDCALL)

#define MKL_DC_ZSYRK_CONVERT(uplo, su, trans, st, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_zsyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        zsyrk_direct((uplo), su, (trans), st, (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define zsyrk(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_ZSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define zsyrk_(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_ZSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define ZSYRK(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_ZSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)

#else

#define MKL_DC_ZSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_zsyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        zsyrk_direct((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define zsyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_ZSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define zsyrk_(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_ZSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define ZSYRK(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_ZSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)

#endif

/* CSYRK_DIRECT */
#if defined(MKL_STDCALL)

#define MKL_DC_CSYRK_CONVERT(uplo, su, trans, st, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_csyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        csyrk_direct((uplo), su, (trans), st, (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define csyrk(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_CSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define csyrk_(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_CSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)
#define CSYRK(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_CSYRK_CONVERT(uplo, uplo_len, trans, trans_len, n, k, alpha, a, lda, beta, c, ldc)

#else

#define MKL_DC_CSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  do { \
    if (MKL_DC_SYRK_CHECKSIZE(n,k)) { \
        mkl_dc_csyrk((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc));\
    } else {  \
        MKL_DIRECT_CALL_INIT_FLAG; \
        csyrk_direct((uplo), (trans), (n), (k), (alpha), (a), (lda), (beta), (c), (ldc), &mkl_direct_call_flag); \
    } \
} while (0)

#define csyrk(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_CSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define csyrk_(uplo, trans, n, k, alpha, a, lda, beta, c, ldc) MKL_DC_CSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
#define CSYRK(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)  MKL_DC_CSYRK_CONVERT(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)

#endif


/* ?AXPY_DIRECT */
#define MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, CHECK, fname_unrolledc, fname_direct)  do { \
    if (CHECK(n)) { \
        fname_unrolledc((n), (alpha), (x), (incx), (y), (incy));\
    } else { \
        MKL_DIRECT_CALL_INIT_FLAG; \
        fname_direct((n), (alpha), (x), (incx), (y), (incy), &mkl_direct_call_flag); \
    } \
} while (0)

#define daxpy(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_DAXPY_CHECKSIZE, mkl_dc_daxpy, daxpy_direct)
#define daxpy_(n,alpha,x,incx,y,incy) MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_DAXPY_CHECKSIZE, mkl_dc_daxpy, daxpy_direct)
#define DAXPY(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_DAXPY_CHECKSIZE, mkl_dc_daxpy, daxpy_direct)

#define saxpy(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_SAXPY_CHECKSIZE, mkl_dc_saxpy, saxpy_direct)
#define saxpy_(n,alpha,x,incx,y,incy) MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_SAXPY_CHECKSIZE, mkl_dc_saxpy, saxpy_direct)
#define SAXPY(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_SAXPY_CHECKSIZE, mkl_dc_saxpy, saxpy_direct)

#define caxpy(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_CAXPY_CHECKSIZE, mkl_dc_caxpy, caxpy_direct)
#define caxpy_(n,alpha,x,incx,y,incy) MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_CAXPY_CHECKSIZE, mkl_dc_caxpy, caxpy_direct)
#define CAXPY(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_CAXPY_CHECKSIZE, mkl_dc_caxpy, caxpy_direct)

#define zaxpy(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_ZAXPY_CHECKSIZE, mkl_dc_zaxpy, zaxpy_direct)
#define zaxpy_(n,alpha,x,incx,y,incy) MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_ZAXPY_CHECKSIZE, mkl_dc_zaxpy, zaxpy_direct)
#define ZAXPY(n,alpha,x,incx,y,incy)  MKL_DC_AXPY_CONVERT(n, alpha, x, incx, y, incy, MKL_DC_ZAXPY_CHECKSIZE, mkl_dc_zaxpy, zaxpy_direct)

/* {S,D}DOT_DIRECT */
static __inline double mkl_dc_ddot_convert(const MKL_INT *n, const double* x, const MKL_INT *incx, const double *y, const MKL_INT *incy) {
    double ret = 0.0;
    if (MKL_DC_DDOT_CHECKSIZE(n)) {
        ret = mkl_dc_ddot((n), (x), (incx), (y), (incy));
    } else {
        ret = ddot_direct((n), (x), (incx), (y), (incy));
    }
    return ret;
}

static __inline float  mkl_dc_sdot_convert(const MKL_INT *n, const float* x, const MKL_INT *incx, const float *y, const MKL_INT *incy) {
    float ret = 0.0;
    if (MKL_DC_SDOT_CHECKSIZE(n)) {
        ret = mkl_dc_sdot((n), (x), (incx), (y), (incy));
    } else {
        ret = sdot_direct((n), (x), (incx), (y), (incy));
    }
    return ret;
}

#define ddot  mkl_dc_ddot_convert
#define ddot_ mkl_dc_ddot_convert
#define DDOT  mkl_dc_ddot_convert

#define sdot  mkl_dc_sdot_convert
#define sdot_ mkl_dc_sdot_convert
#define SDOT  mkl_dc_sdot_convert


#ifdef __cplusplus
}
#endif

#endif /* #ifdef MKL_DIRECT_CALL */
#endif /* _MKL_DIRECT_CALL_H */
