// Program that validates if a credit card number is valid

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void recivecardnum (char cardnumber[17]);
void validatelength (char cardnumber[17], bool *isvalid);
int validatestart (char cardnumber[17], bool *isvalid);
void validatechecksum (char cardnumber[17], bool *isvalid);

// Start main function
int main(int argc, char const *argv[])
{
    char cardnumber[17];
    bool isvalid = true;
    int cardname;

    recivecardnum(cardnumber);

    validatelength(cardnumber, &isvalid);
    if (isvalid == false)
    {
        // Invalid in length
        return 1;
    }

    cardname = validatestart (cardnumber, &isvalid);
    if (isvalid == false)
    {
        // Invalid in the start
        return 2;
    }

    validatechecksum (cardnumber, &isvalid);
    if (isvalid == false)
    {
        // Invalid in Checksum
        return 3;
    }

    switch (cardname)
    {
        case 1:
            printf("American Express\n\n");
            break;
        case 2:
            printf("MasterCard\n\n");
            break;
        case 3:
            printf("Visa\n\n");
            break;
    }

    return 0;
}

// Gets the card number
void recivecardnum (char cardnumber[17])
{
    int i;
    int temp = 0;

    while (temp == 0)
    {
        printf("\nEnter the credit card number: ");
        scanf("%s", cardnumber);

        i = 0;
        while (cardnumber[i] != '\0')
        {
            temp = isdigit(cardnumber[i]);
            if (temp == 0)
            {
                printf("Error\n");
                fflush(stdin);
                break;
            }
            i++;
        }
    }
}

// Validates length and the start of the card number
void validatelength (char cardnumber[17], bool *isvalid)
{
    int length;

    length = strlen(cardnumber);
    if (length != 13 && length != 15 && length != 16)
    {
        printf("Invalid\n");
        *isvalid = false;
    }
}

// Validates the start of the credit card number and returns:
// 1 = American Express
// 2 = MasterCard
// 3 = Visa
int validatestart (char cardnumber[17], bool *isvalid)
{
    int temp, i;

    if (cardnumber[0] == '3')
    {
        if (cardnumber[1] == '4' || cardnumber[1] == '7')
        {
            return 1;
        }
    }

    if (cardnumber[0] == '5')
    {
        temp = cardnumber[1] - 48;
        if (temp >= 1 && temp <= 5)
        {
            return 2;
        }
    }

    if (cardnumber[0] == '2')
    {
        for (i = 0; i < 3; i++)
        {
            if (cardnumber[i] == '2')
            {
                temp = 1;
            }
            else
            {
                break;
            }
        }
        if (temp == 1)
        {
            return 2;
        }
    }

    if (cardnumber [0] == '4')
    {
        return 3;
    }

    printf("Invalid\n");
    *isvalid = false;
    return -1;
}

// Validates Checksum of the credit card number to determinate if is valid
void validatechecksum (char cardnumber[17], bool *isvalid)
{
    int length, i, j, sum1, sum2;
    int temp1[17];
    char temp2[17];

    sum1 = 0;
    sum2 = 0;
    length = strlen(cardnumber);

    for (i = 0; i < length; i++)
    {
        temp1[i] = cardnumber[i] - 48;
    }

    for (i = length - 2; i >= 0; i -= 2)
    {
        temp1[i] *= 2;
    }

    for (i = 0; i < 16; i++)
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

    for (i = 0; i < 16; i++)
    {
        sum1 += (temp2[i] - 48);
    }

    for (i = length - 1; i >= 0; i -= 2)
    {
        sum2 += temp1[i];
    }
    sum1 += sum2;

    if (sum1 % 10 == 0)
    {
        *isvalid = true;
    }
    else
    {
        printf("Invalid\n");
        *isvalid = false;
    }
}
