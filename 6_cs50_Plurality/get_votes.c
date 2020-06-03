// Gets the Votes from users

#include <stdio.h>
#include <string.h>
#include "Plurality_Variables.h"

void get_votes(CANDIDATE *candidatos)
{
    int i, j, temp;
    char vote[50];

    num_votes = get_numvotes();

    for (i = 0; i < num_votes; i++)
    {
        printf("Vote: ");
        scanf("%s", vote);
        for (j = 0; j < num_candidates; j++)
        {
            temp = strcmp(candidatos[j].name, vote);
            if (temp == 0)
            {
                candidatos[j].votes++;
                break;
            }
        }
    }

    for (i = 0, j = 0; i < num_candidates; i++)
    {
        j += candidatos[i].votes;
    }
    invalid_votes = num_votes - j;
}
