#include <stdio.h>

#include "mh_bmath/mh_bmath.h"
#include "mh_bstring/mh_bstring.h"

int main(int argc, char *argv[]) {
	
	signed failedTests = 0;
	
	double testFloat = 1.25;
	signed testAbsInt1 = -23;
	signed testAbsInt2 = 7;
	signed long testAbsLong1 = -54298234;
	signed long testAbsLong2 = 42390942;
	
	signed intFracResult[] = {0, 0};
	double doubleFracResult[] = {0.0, 0.0};
	
	mh_bmath_dtif(&(intFracResult[0]), testFloat, 0.0);
	failedTests += ((intFracResult[0] == 1) && (intFracResult[1] == 4));
	mh_bmath_dtdf(&(doubleFracResult[0]), testFloat, 0.0);
	failedTests += ((doubleFracResult[0] == 1.0) && (doubleFracResult[1] == 4.0));
	
	failedTests += (mh_bmath_iabs(testAbsInt1) != -testAbsInt1);
	failedTests += (mh_bmath_iabs(testAbsInt2) != testAbsInt2);
	failedTests += (mh_bmath_labs(testAbsLong1) != -testAbsLong1);
	failedTests += (mh_bmath_labs(testAbsLong2) != testAbsLong2);
	
	char lower[] = "!@#$%abcdefghijklmnopqrstuvwxyz12345";
	printf("%s -> ", lower);
	mh_bstring_upper(lower);
	printf("%s\n", lower);
	
	char upper[] = "12345ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%";
	printf("%s -> ", upper);
	mh_bstring_lower(upper);
	printf("%s\n", upper);
	
	return failedTests;
	
}
