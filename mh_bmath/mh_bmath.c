#include <stdio.h>
#include <math.h>

#include "mh_bmath.h"

/* 
 * Decimal to Integer Fraction
 * 
 * Converts a double to a ratio of integers
 * 
 * nd is a pointer to at least two integers
 * num is the double to convert to a ratio of integers
 * err is the maximum error when finding a solution
 * 
 * The value returned will be 0 if an exact ratio is found, otherwise, a non-zero value
 * The numerator of the result is stored in nd[0] and the denominator is in nd[1]
 */
int mh_bmath_dtif(int *nd, double num, double err) {
	
	double numwhole, numfrac;
	register signed f0[2] = {0, 1}, f1[2] = {1, 1}, f2[2] = {0, 1};
	register unsigned gtm;
	register double currerr;
	
	numfrac = modf(num, &numwhole);
	
	while((currerr = fabs(((double)f2[0])/((double)f2[1]) - numfrac)) > err) {
		f2[0] = f0[0] + f1[0];
		f2[1] = f0[1] + f1[1];
		gtm = (numfrac >= ((double)f2[0])/((double)f2[1]));
		f0[0] = gtm * f2[0] + !gtm * f0[0];
		f0[1] = gtm * f2[1] + !gtm * f0[1];
		f1[0] = !gtm * f2[0] + gtm * f1[0];
		f1[1] = !gtm * f2[1] + gtm * f1[1];
	}
	
	nd[0] = f2[0] + (int)numwhole * f2[1];
	nd[1] = f2[1];
	
	return (currerr > 0.0);

}

/* 
 * Decimal to Double Fraction
 * 
 * Converts a double to a ratio of integer doubles
 * 
 * nd is a pointer to at least two doubles
 * num is the double to convert to a ratio of integer doubles
 * err is the maximum error when finding a solution
 * 
 * The value returned will be 0 if an exact ratio is found, otherwise, a non-zero value
 * The numerator of the result is stored in nd[0] and the denominator is in nd[1]
 */
int mh_bmath_dtdf(double *nd, double num, double err) {
	
	double numwhole, numfrac;
	register double f0[2] = {0.0, 1.0}, f1[2] = {1.0, 1.0}, f2[2] = {0.0, 1.0};
	register unsigned gtm;
	register double currerr;
	
	numfrac = modf(num, &numwhole);
	
	while((currerr = fabs((f2[0])/(f2[1]) - numfrac)) > err) {
		f2[0] = f0[0] + f1[0];
		f2[1] = f0[1] + f1[1];
		gtm = (numfrac >= (f2[0])/(f2[1]));
		f0[0] = gtm * f2[0] + !gtm * f0[0];
		f0[1] = gtm * f2[1] + !gtm * f0[1];
		f1[0] = !gtm * f2[0] + gtm * f1[0];
		f1[1] = !gtm * f2[1] + gtm * f1[1];
	}
	
	nd[0] = f2[0] + numwhole * f2[1];
	nd[1] = f2[1];
	
	return (currerr > 0.0);

}

#ifndef _MH_BMATH_LESS_

/*
 * Integer Absolute Value
 * I'm not sure why anybody would need this, but just in case
 * 
 * Returns the absolute value of integer num
 */
signed mh_bmath_iabs(signed num) {
	
	register mask;
	
	mask = num >> _INT_BITS_;
	
	return (num ^ mask) - mask;
	
}

/* 
 * Long Integer Absolute Value
 * 
 * Returns the absolute value of long integer num
 */
signed long mh_bmath_labs(signed long num) {
	
	register long mask;
	
	mask = num >> _LONG_BITS_;
	
	return (num ^ mask) - mask;
	
}

#endif
