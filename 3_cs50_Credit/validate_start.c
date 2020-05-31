// Validates the start of the credit card number

#include <string.h>
#include <stdbool.h>
#include "vars-credit.h"

bool validate_start (CREDITCARD *card)
{
    int temp, i;

    // validates the start of American Express: '34' '37'
    if (card->num[0] == '3')
        if (card->num[1] == '4' || card->num[1] == '7')
        {
            strcpy(card->name, "American Express");
            return true;
        }

    // Validates the start of MasterCard
    // start From '51' to '55'
    if (card->num[0] == '5')
    {
        temp = card->num[1] - 48;
        if (temp >= 1 && temp <= 5)
        {
            strcpy(card->name, "MasterCard");
            return true;
        }
    }
    // start '222'
    for (i = 0, temp = 0; i < 3; i++)
    {
        if (card->num[i] == '2')
            temp = 1;
        else break;
    }
    if (temp == 1)
    {
        strcpy(card->name, "MasterCard");
        return true;
    }

    // Validates the start of visa '4'
    if (card->num[0] == '4')
    {
        strcpy(card->name, "Visa");
        return true;
    }

    // No valid start found
    return false;
}
