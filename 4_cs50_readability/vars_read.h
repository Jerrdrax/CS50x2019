// Variables for readability

#ifndef VARS_READ_H
#define VARS_READ_H

#define TXTMAXSIZE 2048

typedef struct
{
    char *text;
    float letters;
    float words;
    float sentences;
}
TXT;

void get_txt (TXT *texto);

void count_letters (TXT *texto);

void count_sentences (TXT *texto);

void count_words (TXT *texto);

void readability (TXT *texto);

#endif
