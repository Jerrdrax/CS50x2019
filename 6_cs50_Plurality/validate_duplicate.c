// Validates if a candidate is duplicated

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Plurality_Variables.h"

bool validate_duplicate (int num_candidates, CANDIDATE *candidatos)
{
    int j, i, temp;

    for (i = 0; i < num_candidates; i++)
    {
        for (j = 0; j < num_candidates; j++)
        {
            temp = strcmp(candidatos[i].name, candidatos[j].name);
            if (j != i && temp == 0)
            {
                printf("Error!\n");
                printf("Duplicated candidates\n");
                return false;
            }
        }
    }

    // Valid
    return true;
}
