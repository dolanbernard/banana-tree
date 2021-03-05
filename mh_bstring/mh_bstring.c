#include "mh_bstring.h"

#define _MH_BSTRING_CASE_DIFF_ ('a' - 'A')

/*
 * String to upper case
 * 
 * Converts latin alphabet characters in a string to their uppercase equivalent
 * 
 * s is a string to convert to uppercase
 */
void mh_bstring_upper(char *s) {
	
	register unsigned i;
	
	for(i = 0; s[i]; i++) {
		s[i] -= (((s[i] < '{') && (s[i] > '`')) * _MH_BSTRING_CASE_DIFF_);
	}
	
}

/*
 * String to upper case
 * 
 * Converts latin alphabet characters in a string to their lowercase equivalent
 * 
 * s is a string to convert to lowercase
 */
void mh_bstring_lower(char *s) {
	
	register unsigned i;
	
	for(i = 0; s[i]; i++) {
		s[i] += (((s[i] < '[') && (s[i] > '@')) * _MH_BSTRING_CASE_DIFF_);
	}
	
}
