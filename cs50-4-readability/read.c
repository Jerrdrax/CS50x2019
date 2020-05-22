// Program that computes the approximate grade level needed to
// comprehend some text.

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void textrecive (char text[2048]);
void textletters (char text[2048], float *letters);
void textwords (char text[2048], float *words);
void textsentences (char text[2048], float *sentences);
void textreadability (char text[2048], float *letters, float *words, float *sentences);

// Start of the main function
int main(int argc, char const *argv[])
{
    char text [2048];
    float letters = 0;
    float words = 0;
    float sentences = 0;

    textrecive(text);

    textletters(text, &letters);

    textwords(text, &words);

    textsentences(text, &sentences);

    textreadability(text, &letters, &words, &sentences);

    //printf("letters: %.0f\n", letters); // Test
    //printf("words: %.0f\n", words); // Test
    //printf("sentences: %.0f\n", sentences); // Test

    return 0;
}

// Gets the text to compute from the user
void textrecive (char text[2048])
{
    int i;

    for (i = 0; i < 2048; i++)
    {
        text[i] = ' ';
    }

    printf("\nText: ");
    fgets(text, 2048, stdin);
}

// Counts the letters in the text
void textletters (char text[2048], float *letters)
{
    int i = 0;
    int temp = 0;

    while (i < 2048)
    {
        temp = isalpha(text[i]);
        if (temp != 0)
        {
            *letters += 1;
        }
        i++;
    }
}

// Counts the words in the text
void textwords (char text[2048], float *words)
{
    int temp;
    int i = 0;

    while (i < 2048)
    {
        temp = isalpha(text[i]);
        if (temp != 0)
        {
            *words += 1;
            while (text[i] != ' ')
            {
                i++;
            }
        }
        i++;
    }
}

// Counts the sentences in the text
void textsentences (char text[2048], float *sentences)
{
    int i = 0;

    while (i < 2048)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            *sentences += 1;
        }
        i++;
    }
}

// Computing the grade of Readability
void textreadability (char text[2048], float *letters, float *words, float *sentences)
{
    float temp, l, s;
    float index = 0;

    temp = 100 / *words;

    l = *letters * temp;
    s = *sentences * temp;

    index = (0.0588 * l) - (0.296 * s) - 15.8 ;
    index = roundf(index);

    if (index < 1)
    {
        printf("\nBefore Grade 1\n\n");
    }
    else if (index >= 16)
    {
        printf("\nGrade 16+\n\n");
    }
    else
    {
        printf("\nGrade: %.0f\n\n", index);
    }
}
