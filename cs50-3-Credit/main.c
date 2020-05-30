// Program that validates if a credit card number is valid
// American Express, MasterCard, Visa

#include <stdio.h>
#include <stdbool.h>
#include "vars-credit.h"

// Start main function
int main(int argc, char const *argv[])
{
    bool isvalid;
    CREDITCARD card1;
    printf("\n");

    isvalid = get_cardnum (&card1);
    if (isvalid == true) printf("%s\n", card1.name);
    else printf("Invalid\n\n");

    isvalid = get_cardnum (&card1);
    if (isvalid == true) printf("%s\n", card1.name);
    else printf("Invalid\n\n");

    printf("\n");
    return 0;
}
