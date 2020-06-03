// Recives the number of votes

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Plurality_Variables.h"

int get_numvotes( )
{
    char num[50];
    int i;
    int temp = 0;

    while (temp == 0)
    {
        printf("Number of voters? ");
        scanf("%s", num);

        i = 0;
        while (num[i] != '\0')
        {
            temp = isdigit(num[i]);
            if (temp == 0)
            {
                printf("Error!\n");
                fflush(stdin);
                break;
            }
            i++;
        }
    }

    temp = atoi(num);
    return temp;
}
