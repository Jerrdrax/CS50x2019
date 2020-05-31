// Counts the letters in the text

#include <ctype.h>
#include "vars_read.h"

void count_letters (TXT *texto)
{
    int temp;
    int i = 0;

    while (texto->text[i] != '\0')
    {
        temp = isalpha(texto->text[i]);

        if (temp != 0)
        {
            texto->letters += 1;
        }
        i++;
    }
}
