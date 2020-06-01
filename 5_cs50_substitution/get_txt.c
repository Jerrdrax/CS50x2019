// Gets the text to encrypt from the user

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vars_cipher.h"

void get_txt( )
{
    int temp;

    text = (char*)calloc(MAXLENGTH, sizeof(char));
    if (text == NULL)
    {
        printf("Error in memory\n");
        exit(1);
    }

    printf("Plaintext: ");
    fgets(text, MAXLENGTH, stdin);

    temp = strlen(text);
    text[temp - 1] = '\0';

    text = realloc(text, temp * sizeof(char));
}
