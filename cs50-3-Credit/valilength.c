// Validates length and the start of the card number

void valilength ( )
{
    int length;

    length = strlen(number);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("Invalid\n");
        isvalid = false;
    }

}
