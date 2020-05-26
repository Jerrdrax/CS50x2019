// Function that gets a credit card number and calls all the validations

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "valilength.c"
#include "valistart.c"
#include "valichecksum.c"

bool get_cardnum (CREDITCARD *card)
{
    bool val;
    int i;
    int temp = 0;

    while (temp == 0)
    {
        printf("\nEnter the credit card number: ");
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

    val = valilength (card);
    if (val == false)
    {
        // Invalid in length
        return false;
    }

    val = valistart (card);
    if (val == false)
    {
        // Invalid in the start
        return false;
    }

    val = valichecksum (card);
    if (val == false)
    {
        // Invalid in Checksum
        return false;
    }

    // Valid card
    return true;
}
