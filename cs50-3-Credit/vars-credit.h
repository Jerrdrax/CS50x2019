// variables for credit card validation program

#ifndef VARS_CREDIT_H
#define VARS_CREDIT_H


// max length of a credit card number
#define MAXLENGTH 17
// max name length of a credit card
#define MAXNAME 17

typedef struct
{
    // credit card numbers
    char num[MAXLENGTH];
    // names of the cards
    char name[MAXNAME];
} CREDITCARD;

// functions
bool get_cardnum (CREDITCARD *card);

bool validate_length (CREDITCARD *card);

bool validate_start (CREDITCARD *card);

bool validate_checksum (CREDITCARD *card);

#endif
