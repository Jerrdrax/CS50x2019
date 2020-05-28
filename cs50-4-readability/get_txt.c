// Gets a text with max size of 'TXTMAXSIZE' and obtains length

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Gets the text to compute from the user
void get_txt (TXT *texto)
{
    int i, temp;

    // initialize to 0 to avoid posible bugs with buff trash
    texto->text = (char*)calloc(TXTMAXSIZE, sizeof(char));
    if (texto->text == NULL)
    {
        exit(1);
    }
    texto->letters = 0;
    texto->words = 0;
    texto->sentences = 0;

    // Gets the text
    printf("Text: ");
    fgets(texto->text, TXTMAXSIZE, stdin);

    temp = strlen(texto->text);
    texto->length = temp;

    temp = temp + sizeof(char);
    texto->text = realloc(texto->text, temp * sizeof(char));

}
