// Program that runs a plurality election

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXCANDIDATES 9
#define MINCANDIDATES 2

typedef struct
{
    char *name;
    int votes;
}
CANDIDATE;



// Start of main function
int main(int argc, char const *argv[])
{
    int i;
    bool isvalid = true;
    int numcandidates = argc - 1;
    CANDIDATE candidates[numcandidates];

    if (numcandidates < MINCANDIDATES || numcandidates > MAXCANDIDATES)
    {
        return 1;
    }

    for (i = 0; i < numcandidates; i++)
    {
        candidates.name = malloc(argv[1]);
    }

    return 0;
}
