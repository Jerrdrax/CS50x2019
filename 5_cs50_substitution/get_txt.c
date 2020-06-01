// Gets the text to encrypt from the user

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vars_cipher.h"

void get_txt(char **texto)
{
    int temp;
    char *tempstring;

    tempstring = (char*)calloc(MAXLENGTH, sizeof(char));
    if (tempstring == NULL)
    {
        printf("Error in memory\n");
        exit(1);
    }

    printf("Plaintext: ");
    fgets(tempstring, MAXLENGTH, stdin);

    temp = strlen(tempstring);
    tempstring[temp - 1] = '\0';

    tempstring = realloc(tempstring, temp * sizeof(char));

    *texto = tempstring;
}
