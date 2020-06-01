// Applies cipher substitution and prints

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "vars_cipher.h"

void cipher( )
{
    int i, j, k, temp;
    char cipher[MAXLENGTH];
    char alphabetlow[ALPHABET];
    char alphabetup[ALPHABET];

    for (i = 0; i < MAXLENGTH; i++)
    {
        cipher[i] = 0;
    }
    for (i = 0, j = 65, k = 97; i < ALPHABET - 1; i++, j++, k++)
    {
        alphabetup[i] = j;
        alphabetlow[i] = k;
    }

    i = 0;
    while (text[i] != '\0')
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            for (j = 0; j < ALPHABET - 1; j++)
            {
                if (text[i] == alphabetup[j])
                {
                    cipher[i] = key[j];
                    cipher[i] = toupper(cipher[i]);
                }
            }
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            for (j = 0; j < ALPHABET - 1; j++)
            {
                if (text[i] == alphabetlow[j])
                {
                    cipher[i] = key[j];
                    cipher[i] = tolower(cipher[i]);
                }
            }
        }
        else
        {
            cipher[i] = text[i];
        }
        i++;
    }

    printf("Ciphertext: %s\n", cipher);
    free(text);
}
