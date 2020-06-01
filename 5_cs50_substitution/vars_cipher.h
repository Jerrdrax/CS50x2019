// variables for substitution

#ifndef VARS_CIPHER_H
#define VARS_CIPHER_H

#include <stdbool.h>

// max length of the txt
#define MAXLENGTH 2048

// number of letters alphabet + \n
#define ALPHABET 27

// global variables
bool isvalid;
char key[ALPHABET];
char *text;

bool get_key (int argc, char const argv[ALPHABET]);

void get_txt( );

void cipher( );


#endif
