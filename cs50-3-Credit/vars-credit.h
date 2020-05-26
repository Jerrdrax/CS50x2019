// variables for credit card validation program

#ifndef VARS_CREDIT_2020_MAY
#define VARS_CREDIT_2020_MAY

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

#endif
