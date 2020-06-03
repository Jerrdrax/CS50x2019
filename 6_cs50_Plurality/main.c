// Program that runs a plurality election

#include <stdio.h>
#include <stdbool.h>
#include "Plurality_Variables.h"

// Start of the main function
int main(int argc, char const *argv[])
{
    bool isvalid;
    CANDIDATE *candidates;
    printf("\n");

    isvalid = get_election(argc, argv, &candidates);
    if (isvalid == false) return 1;

    get_votes(candidates);
    printf("\n");

    print_winner(candidates);

    printf("\n\n");
    return 0;
}
