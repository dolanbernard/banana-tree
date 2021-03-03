#include <stdio.h>
#include "math/mh_bmath.h"

int main(int argc, char *argv[]) {
	
	signed failedTests = 0;
	
	double testFloat = 1.25;
	signed testAbsInt1 = -23;
	signed testAbsInt2 = 7;
	signed long testAbsLong1 = -54298234;
	signed long testAbsLong2 = 42390942;
	
	signed intFracResult[] = {0, 0};
	double doubleFracResult[] = {0.0, 0.0};
	
	mh_bmath_dtif(&intFracResult, testFloat, 0.0);
	failedTests += ((intFracResult[0] == 1) && (intFracResult[1] == 4));
	mh_bmath_dtdf(&doubleFracResult, testFloat, 0.0);
	failedTests += ((doubleFracResult[0] == 1.0) && (doubleFracResult[1] == 4.0));
	
	failedTests += (mh_bmath_iabs(testAbsInt1) != -testAbsInt1);
	failedTests += (mh_bmath_iabs(testAbsInt2) != testAbsInt2);
	failedTests += (mh_bmath_labs(testAbsLong1) != -testAbsLong1);
	failedTests += (mh_bmath_labs(testAbsLong2) != testAbsLong2);
	
	return failedTests;
	
}
