// Validates the length of a card number in a string and returns boolean value

bool valilength (CREDITCARD *card)
{
    int length;

    length = strlen(card->num);

    if (length != 13 && length != 15 && length != 16)
    {
        return false;
    }

    return true;
}
