#ifndef _mh_bmath_h_
#define _mh_bmath_h_

#define _INT_BYTES_ (sizeof(int))
#define _INT_BITS_ ((_INT_BYTES_) << 2)
#define _LONG_BYTES_ (sizeof(long))
#define _LONG_BITS_ ((_LONG_BYTES_) << 2)

int mh_bmath_dtif(int *nd, double num, double err);
int mh_bmath_dtdf(double *nd, double num, double err);

#ifndef _MH_BMATH_LESS_

signed mh_bmath_iabs(signed num);
signed long mh_bmath_labs(signed long num);

#endif

#endif
