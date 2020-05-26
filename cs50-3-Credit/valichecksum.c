// Validates Checksum of the credit card number
// to determinate if is valid.

void valichecksum ( )
{
    int length, i, j, sum1, sum2;
    int temp1[MAXLENGTH];
    char temp2[MAXLENGTH];

    sum1 = 0;
    sum2 = 0;
    length = strlen(number);

    for (i = 0; i < length; i++)
    {
        temp1[i] = number[i] - 48;
    }

    for (i = length - 2; i >= 0; i -= 2)
    {
        temp1[i] *= 2;
    }

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

    for (i = 0; i < MAXLENGTH; i++)
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
        isvalid = true;
    }
    else
    {
        printf("Invalid\n");
        isvalid = false;
    }
}
