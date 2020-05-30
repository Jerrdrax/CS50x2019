// Function that gets a credit card number and calls all the validations

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "vars-credit.h"

bool get_cardnum (CREDITCARD *card)
{
    bool validator;
    int i;
    int temp = 0;

    while (temp == 0)
    {
        printf("Enter the credit card number: ");
        scanf("%s", &card->num);

        card->num[MAXLENGTH - 1] = '\0';
        i = 0;
        while (card->num[i] != '\0')
        {
            temp = isdigit(card->num[i]);
            if (temp == 0)
            {
                printf("Error\n");
                fflush(stdin);
                break;
            }
            i++;
        }
    }

    // Length validation
    validator = validate_length(card); if(validator == false) return validator;

    // Start validation
    validator = validate_start(card); if(validator == false) return validator;

    // Checksum validation
    validator = validate_checksum(card); if(validator == false) return validator;

    // Valid card
    return true;
}
