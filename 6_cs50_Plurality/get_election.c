// Gets, validates and initialize arguments for plurality election program

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Plurality_Variables.h"

bool get_election (int argc, char const *argv[], CANDIDATE **candidatos)
{
    bool isvalid;
    int i;
    num_candidates = argc - 1;
    CANDIDATE *tempcandidato;

    if (num_candidates < MINCANDIDATES || num_candidates > MAXCANDIDATES)
    {
        printf("Error!\n");
        printf("Usage: ./plurality candidate candidate ...\n");
        printf("Number of candidates: Min=%i Max=%i\n", MINCANDIDATES, MAXCANDIDATES);
        return false;
    }
    tempcandidato = (CANDIDATE*)calloc(num_candidates, sizeof(CANDIDATE));
    if (tempcandidato == NULL)
    {
        printf("Error in Memory!\n");
        return false;
    }

    int templengths[num_candidates];
    for (i = 0; i < num_candidates; i++)
    {
        templengths[i] = strlen(argv[i + 1]);
        templengths[i]++;
    }

    for (i = 0; i < num_candidates; i++)
    {
        tempcandidato[i].name = (char*)calloc(templengths[i], sizeof(char));
        if (tempcandidato[i].name == NULL)
        {
            printf("Error in Memory!\n");
            return false;
        }
        strcpy(tempcandidato[i].name, argv[i + 1]);
    }

    for (i = 0; i < num_candidates; i++)
    {
        tempcandidato[i].votes = 0;
    }

    isvalid = validate_duplicate (num_candidates, tempcandidato);
    if (isvalid == false) return false;

    // Valid
    *candidatos = tempcandidato;
    return true;
}
