/* ./src_f77/slanhs.f -- translated by f2c (version 20030320).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <punc/vf2c.h>

/* Table of constant values */

static integer c__1 = 1;

doublereal slanhs_(char *norm, integer *n, real *a, integer *lda, real *work, 
	ftnlen norm_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4;
    real ret_val, r__1, r__2, r__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
    static real sum, scale;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    static real value;
    extern /* Subroutine */ int slassq_(integer *, real *, integer *, real *, 
	    real *);


/*  -- LAPACK auxiliary routine (version 3.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd., */
/*     Courant Institute, Argonne National Lab, and Rice University */
/*     October 31, 1992 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SLANHS  returns the value of the one norm,  or the Frobenius norm, or */
/*  the  infinity norm,  or the  element of  largest absolute value  of a */
/*  Hessenberg matrix A. */

/*  Description */
/*  =========== */

/*  SLANHS returns the value */

/*     SLANHS = ( max(abs(A(i,j))), NORM = 'M' or 'm' */
/*              ( */
/*              ( norm1(A),         NORM = '1', 'O' or 'o' */
/*              ( */
/*              ( normI(A),         NORM = 'I' or 'i' */
/*              ( */
/*              ( normF(A),         NORM = 'F', 'f', 'E' or 'e' */

/*  where  norm1  denotes the  one norm of a matrix (maximum column sum), */
/*  normI  denotes the  infinity norm  of a matrix  (maximum row sum) and */
/*  normF  denotes the  Frobenius norm of a matrix (square root of sum of */
/*  squares).  Note that  max(abs(A(i,j)))  is not a  matrix norm. */

/*  Arguments */
/*  ========= */

/*  NORM    (input) CHARACTER*1 */
/*          Specifies the value to be returned in SLANHS as described */
/*          above. */

/*  N       (input) INTEGER */
/*          The order of the matrix A.  N >= 0.  When N = 0, SLANHS is */
/*          set to zero. */

/*  A       (input) REAL array, dimension (LDA,N) */
/*          The n by n upper Hessenberg matrix A; the part of A below the */
/*          first sub-diagonal is not referenced. */

/*  LDA     (input) INTEGER */
/*          The leading dimension of the array A.  LDA >= max(N,1). */

/*  WORK    (workspace) REAL array, dimension (LWORK), */
/*          where LWORK >= N when NORM = 'I'; otherwise, WORK is not */
/*          referenced. */

/* ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --work;

    /* Function Body */
    if (*n == 0) {
	value = 0.f;
    } else if (lsame_(norm, "M", (ftnlen)1, (ftnlen)1)) {

/*        Find max(abs(A(i,j))). */

	value = 0.f;
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/* Computing MIN */
	    i__3 = *n, i__4 = j + 1;
	    i__2 = min(i__3,i__4);
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* Computing MAX */
		r__2 = value, r__3 = (r__1 = a[i__ + j * a_dim1], dabs(r__1));
		value = dmax(r__2,r__3);
/* L10: */
	    }
/* L20: */
	}
    } else if (lsame_(norm, "O", (ftnlen)1, (ftnlen)1) || *(unsigned char *)
	    norm == '1') {

/*        Find norm1(A). */

	value = 0.f;
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    sum = 0.f;
/* Computing MIN */
	    i__3 = *n, i__4 = j + 1;
	    i__2 = min(i__3,i__4);
	    for (i__ = 1; i__ <= i__2; ++i__) {
		sum += (r__1 = a[i__ + j * a_dim1], dabs(r__1));
/* L30: */
	    }
	    value = dmax(value,sum);
/* L40: */
	}
    } else if (lsame_(norm, "I", (ftnlen)1, (ftnlen)1)) {

/*        Find normI(A). */

	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    work[i__] = 0.f;
/* L50: */
	}
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/* Computing MIN */
	    i__3 = *n, i__4 = j + 1;
	    i__2 = min(i__3,i__4);
	    for (i__ = 1; i__ <= i__2; ++i__) {
		work[i__] += (r__1 = a[i__ + j * a_dim1], dabs(r__1));
/* L60: */
	    }
/* L70: */
	}
	value = 0.f;
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing MAX */
	    r__1 = value, r__2 = work[i__];
	    value = dmax(r__1,r__2);
/* L80: */
	}
    } else if (lsame_(norm, "F", (ftnlen)1, (ftnlen)1) || lsame_(norm, "E", (
	    ftnlen)1, (ftnlen)1)) {

/*        Find normF(A). */

	scale = 0.f;
	sum = 1.f;
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/* Computing MIN */
	    i__3 = *n, i__4 = j + 1;
	    i__2 = min(i__3,i__4);
	    slassq_(&i__2, &a[j * a_dim1 + 1], &c__1, &scale, &sum);
/* L90: */
	}
	value = scale * sqrt(sum);
    }

    ret_val = value;
    return ret_val;

/*     End of SLANHS */

} /* slanhs_ */
