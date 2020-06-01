// Validates the command line Arguments and saves the key in global variable

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "vars_cipher.h"

bool get_key (int argc, char const argv[ALPHABET])
{
    int i, j, temp;
    char tempkey[ALPHABET];

    if (argc != 2) return false;

    if (strlen(argv) != ALPHABET - 1) return false;

    i = 0;
    while (i < ALPHABET - 1)
    {
        temp = isalpha(argv[i]);
        if (temp == 0) return false;
        i++;
    }

    // Checks for repetition of a letter in key
    strcpy(tempkey, argv);
    for (i = 0; i < ALPHABET - 1; i++)
        tempkey[i] = tolower(tempkey[i]);

    for (i = 0; i < ALPHABET - 1; i++)
        for (j = 0; j < ALPHABET - 1; j++)
            if (tempkey[i] == tempkey[j] && i != j) return false;

    // Valid
    strcpy(key, argv);
    return true;
}
