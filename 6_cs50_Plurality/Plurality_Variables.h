// Variables for plurality program

#ifndef PLURALITY_VARIABLES_H
#define PLURALITY_VARIABLES_H

// Max and Min number of candidates
#define MAXCANDIDATES 9
#define MINCANDIDATES 2

#include <stdbool.h>

typedef struct
{
    char *name;
    int votes;
}
CANDIDATE;

// Number of voters
int num_votes;
// Counts the number of invalid votes emited
int invalid_votes;
// Number of candidates in the election
int num_candidates;

bool get_election (int argc, char const *argv[], CANDIDATE **candidatos);

bool validate_duplicate (int num_candidates, CANDIDATE *candidatos);

int get_numvotes( );

void get_votes(CANDIDATE *candidatos);

void print_winner(CANDIDATE *candidatos);

#endif
