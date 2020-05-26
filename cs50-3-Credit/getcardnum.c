// Function that gets the credit card number

void getcardnum ( )
{
    int i;
    int temp = 0;

    while (temp == 0)
    {
        printf("\nEnter the credit card number: ");
        scanf("%s", number);

        i = 0;
        
        while (number[i] != '\0')
        {
            temp = isdigit(number[i]);
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
