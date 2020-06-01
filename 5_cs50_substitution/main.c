// Program that implements a substitution cipher.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vars_cipher.h"

// Start of the function main
int main(int argc, char const *argv[])
{
    char *text;
    bool isvalid;
    printf("\n");

    isvalid = get_key(argc, argv[1]);
    if (isvalid == false)
    {
        printf("Error!\n");
        printf("Usage: ./substitution key of 26 characters\n");
        return 1;
    }

    get_txt(&text);
    cipher(&text);

    printf("\n");
    return 0;
}
