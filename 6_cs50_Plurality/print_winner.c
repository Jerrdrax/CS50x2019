// Prints the winner or winners

#include <stdio.h>
#include <stdlib.h>
#include "Plurality_Variables.h"

void print_winner(CANDIDATE *candidatos)
{
    int i, mostvotes;

    mostvotes = 0;
    for (i = 1; i < num_candidates; i++)
    {
        if (candidatos[i].votes > candidatos[mostvotes].votes)
        {
            mostvotes = i;
        }
    }

    if (candidatos[mostvotes].votes != 0)
    {
        printf("Winner: %s", candidatos[mostvotes].name);
    }
    else
    {
        printf("There is no winner");
    }

    for (i = 0; i < num_candidates; i++)
    {
        if (candidatos[i].votes != 0)
        {
            if (i != mostvotes && candidatos[mostvotes].votes == candidatos[i].votes)
            {
                printf(" & %s", candidatos[i].name);
            }
        }
    }

    if (invalid_votes != 0)
    {
        printf("\nInvalid votes: %i", invalid_votes);
    }

    for (i = 0; i < num_candidates; i++)
    {
        free(candidatos[i].name);
    }
}
