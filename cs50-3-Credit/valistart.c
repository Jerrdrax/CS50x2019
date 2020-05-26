// Validates the start of the credit card number

void validatestart ( )
{
    int temp, i;

    if (number[0] == '3')
    {
        if (number[1] == '4' || number[1] == '7')
        {
            strcpy(cardname, AME_EXP);
            return;
        }
    }

    if (number[0] == '5')
    {
        temp = number[1] - 48;
        if (temp >= 1 && temp <= 5)
        {
            strcpy(cardname, MAS_CAR);
            return;
        }
    }

    temp = 0;
    for (i = 0; i < 3; i++)
    {
        if (number[i] == '2')
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
        strcpy(cardname, MAS_CAR);
        return;
    }

    if (number[0] == '4')
    {
        strcpy(cardname, VISA);
        return;
    }

    printf("Invalid\n");
    isvalid = false;
}
