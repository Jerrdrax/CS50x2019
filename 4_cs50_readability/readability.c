// Computing the grade of Readability

#include <stdio.h>
#include <math.h>
#include "vars_read.h"

void readability (TXT *texto)
{
    // counts the letters
    count_letters(texto);

    // counts the words
    count_words(texto);

    // counts the sentences
    count_sentences(texto);

    float temp, l, s;
    float index = 0;

    temp = 100 / texto->words;

    l = texto->letters * temp;
    s = texto->sentences * temp;

    index = (0.0588 * l) - (0.296 * s) - 15.8 ;
    index = roundf(index);

    if (index < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("\nGrade 16+\n");
    }
    else
    {
        printf("\nGrade: %.0f\n", index);
    }
}
