// Program that runs a plurality election

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXCANDIDATES 9
#define MINCANDIDATES 2

typedef struct
{
    char *name;
    int votes;
}
CANDIDATE;

void recivenumvotes (int *votes);
bool valduplicated (int *numcandidates, CANDIDATE candidates[9]);
void askvotes (int *numcandidates, CANDIDATE candidates[9], int *votes, int *invalidvotes);
void printwinner(int *numcandidates, CANDIDATE candidates[9]);

// Start of main function
int main(int argc, char const *argv[])
{
    bool isvalid = true;
    int i, votes;
    int invalidvotes = 0;
    int numcandidates = argc - 1;
    CANDIDATE candidates[numcandidates];

    if (numcandidates < MINCANDIDATES || numcandidates > MAXCANDIDATES)
    {
        printf("Error\n");
        printf("Usage: ./plurality candidate candidate ...\n");
        return 1;
    }

    for (i = 0; i < numcandidates; i++)
    {
        candidates[i].name = malloc(strlen(argv[i + 1] + 1));
        if (candidates[i].name == NULL)
        {
            printf("Error in Memory\n");
            return 1;
        }
        strcpy(candidates[i].name, argv[i + 1]);
    }
    for (i = 0; i < numcandidates; i++)
    {
        candidates[i].votes = 0;
    }

    isvalid = valduplicated (&numcandidates, candidates);
    if (isvalid == false)
    {
        return 1;
    }

    recivenumvotes(&votes);

    askvotes (&numcandidates, candidates, &votes, &invalidvotes);

    printwinner(&numcandidates, candidates);

    if (invalidvotes != 0)
    {
        printf("Invalid votes: %i\n", invalidvotes);
    }

    for (i = 0; i < numcandidates; i++)
    {
        free(candidates[i].name);
    }
    return 0;
}

// Validates if a candidate is duplicated
bool valduplicated (int *numcandidates, CANDIDATE candidates[9])
{
    int j, i, temp;

    for (i = 0; i < *numcandidates; i++)
    {
        for (j = 0; j < *numcandidates; j++)
        {
            temp = strcmp(candidates[i].name, candidates[j].name);
            if (j != i && temp == 0)
            {
                printf("\nError duplicated candidates\n\n");
                return false;
            }
        }
    }
    return true;
}

// Recives number of votes
void recivenumvotes (int *votes)
{
    char num[20];
    int temp = 0;
    int i, j;

    while (temp == 0)
    {
        printf("Number of voters: ");
        scanf("%s", num);

        i = 0;
        while (num[i] != '\0')
        {
            temp = isdigit(num[i]);
            if (temp == 0)
            {
                printf("Error\n");
                fflush(stdin);
                break;
            }
            i++;
        }
    }
    *votes = atoi(num);
}

// Ask Votes from user
void askvotes (int *numcandidates, CANDIDATE candidates[9], int *votes, int *invalidvotes)
{
    int i, j, temp;
    char vote[30];

    for (i = 0; i < *votes; i++)
    {
        printf("Vote: ");
        scanf("%s", vote);
        for (j = 0; j < *numcandidates; j++)
        {
            temp = strcmp(candidates[j].name, vote);
            if (temp == 0)
            {
                candidates[j].votes++;
                break;
            }
        }
    }

    for (i = 0, j = 0; i < *numcandidates; i++)
    {
        j += candidates[i].votes;
    }
    *invalidvotes = *votes - j;
}

// Prints winner or winners
void printwinner(int *numcandidates, CANDIDATE candidates[9])
{
    int i, mostvotes;

    mostvotes = 0;
    for (i = 1; i < *numcandidates; i++)
    {
        if (candidates[i].votes > candidates[mostvotes].votes)
        {
            mostvotes = i;
        }
    }

    if (candidates[mostvotes].votes != 0)
    {
        printf("The winner is: %s", candidates[mostvotes].name);
    }
    else
    {
        printf("There is no winner");
    }

    for (i = 0; i < *numcandidates; i++)
    {
        if (i != mostvotes && candidates[mostvotes].votes == candidates[i].votes)
        {
            if (candidates[i].votes != 0)
            {
                printf(" and %s", candidates[i].name);
            }
        }
    }
    printf("\n\n");
}
