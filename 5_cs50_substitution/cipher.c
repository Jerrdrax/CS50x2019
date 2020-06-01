// Applies cipher substitution and prints

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "vars_cipher.h"

void cipher(char **texto)
{
    int i, j, k, temp;
    char *tempstring, *cipher;
    char alphabetlow[ALPHABET];
    char alphabetup[ALPHABET];

    tempstring = *texto;
    temp = strlen(tempstring);
    cipher = (char*)calloc(temp, sizeof(char));
    if (cipher == NULL)
    {
        printf("Error in memory\n");
        exit(1);
    }

    for (i = 0, j = 65, k = 97; i < ALPHABET - 1; i++, j++, k++)
    {
        alphabetup[i] = j;
        alphabetlow[i] = k;
    }

    i = 0;
    while (tempstring[i] != '\0')
    {
        if (tempstring[i] >= 65 && tempstring[i] <= 90)
        {
            for (j = 0; j < ALPHABET - 1; j++)
            {
                if (tempstring[i] == alphabetup[j])
                {
                    cipher[i] = key[j];
                    cipher[i] = toupper(cipher[i]);
                }
            }
        }
        else if (tempstring[i] >= 97 && tempstring[i] <= 122)
        {
            for (j = 0; j < ALPHABET - 1; j++)
            {
                if (tempstring[i] == alphabetlow[j])
                {
                    cipher[i] = key[j];
                    cipher[i] = tolower(cipher[i]);
                }
            }
        }
        else
        {
            cipher[i] = tempstring[i];
        }
        i++;
    }

    printf("Ciphertext: %s\n", cipher);
    free(tempstring);
    free(cipher);
}
