// Program that prints in terminal pyramids of # with 2 spaces in between
// from 1 to 8 height

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void reciveheight (char inputheight[2], int *pheight);
void printpyramid (int *height);

int main(int argc, char const *argv[]) {
    int height;
    char inputheight[2];

    reciveheight(inputheight, &height);
    //printf("%i\n", height); // reciveheight Test

    printpyramid (&height);
    printf("\n");

    return 0;
}

// Recives the height of the pyramid from the user
void reciveheight (char inputheight[2], int *pheight)
{
    int i;
    int temp = 0;
    *pheight = 0;

    while (temp == 0 || *pheight < 1 || *pheight > 8)
    {
        printf("\nHeight: ");
        scanf("%s", inputheight);

        i = 0;
        while (inputheight[i] != '\0')
        {
            temp = isdigit(inputheight[i]);
            if (temp == 0)
            {
                break;
            }
            i++;
        }

        *pheight = atoi(inputheight);

        if (temp == 0 || *pheight < 1 || *pheight > 8)
        {
            printf("Error type a number between 1 and 8\n");
            fflush(stdin);
        }
    }
}

// Prints the pyramid
void printpyramid (int *height)
{
    int i, j, k, l;
    int spaces = *height;

    for (i = 0; i < *height; i++)
    {
        for (l = 0; l < spaces - 1; l++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }
        spaces--;
        printf("\n");
    }

}
