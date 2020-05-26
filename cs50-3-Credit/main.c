// Program that validates if a credit card number is valid
// American Express, MasterCard, Visa

#include "vars-credit.h"
#include "getcardnum.c"

// Start main function
int main(int argc, char const *argv[])
{
    bool isvalid = true;
    CREDITCARD card1;

    isvalid = get_cardnum (&card1);
    if (isvalid == false)
    {
        printf("Invalid\n\n");
        return 1;
    }
    if (isvalid == true)
        printf("%s\n\n", card1.name);

    return 0;
}
