// Validates Checksum of a credit card number to determinate if is valid.

#include <string.h>
#include <stdbool.h>
#include "vars-credit.h"

bool validate_checksum (CREDITCARD *card)
{
    int length, i, j, sum1, sum2;
    int temp1[MAXLENGTH];
    char temp2[MAXLENGTH];

    sum1 = 0;
    sum2 = 0;
    length = strlen(card->num);

    // Converts from char to ints the card number
    for (i = 0; i < length; i++)
    {
        temp1[i] = card->num[i] - 48;
    }

    // multiplies by 2 starting with the second to last
    for (i = length - 2; i >= 0; i -= 2)
    {
        temp1[i] *= 2;
    }

    // Converts back to char the results of the multplications
    for (i = 0; i < MAXLENGTH; i++)
    {
        temp2[i] = '0';
    }

    j = 0;
    i = length - 2;
    while (i >= 0)
    {
        if (temp1[i] > 9)
        {
            temp2[j] = 49;
            temp2[j + 1] = (temp1[i] - 10) + 48;
            j += 2;
        }
        else
        {
            temp2[j] = temp1[i] + 48;
            j++;
        }
        i -= 2;
    }

    // sums all the results digits
    for (i = 0; i < MAXLENGTH; i++)
    {
        sum1 += (temp2[i] - 48);
    }

    // sums the rest of digits
    for (i = length - 1; i >= 0; i -= 2)
    {
        sum2 += temp1[i];
    }
    sum1 += sum2;

    // checks if ends in 0
    if (sum1 % 10 == 0) return true;
    else return false;
}
