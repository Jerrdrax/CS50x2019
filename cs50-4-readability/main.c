// Program that computes the approximate grade level needed to
// comprehend some text.

#include "vars_read.h"
#include "get_txt.c"
#include "readability.c"

// Start of the main function
int main(int argc, char const *argv[])
{
    TXT text1;
    printf("\n");

    get_txt(&text1);

    readability(&text1);

    printf("\n");
    free(text1.text);
    return 0;
}
