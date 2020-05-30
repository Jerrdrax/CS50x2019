// Validates the length of a card number in a string and returns boolean value

#include <string.h>
#include <stdbool.h>
#include "vars-credit.h"

bool validate_length (CREDITCARD *card)
{
    int length;

    length = strlen(card->num);

    // check if false
    if (length != 13 && length != 15 && length != 16)
        return false;

    // true
    return true;
}
