// Counts the sentences in the text

#include "vars_read.h"

void count_sentences (TXT *texto)
{
    int i = 0;

    while (texto->text[i] != '\0')
    {
        if (texto->text[i] == '.' || texto->text[i] == '!' || texto->text[i] == '?')
        {
            texto->sentences += 1;
        }
        i++;
    }
}
