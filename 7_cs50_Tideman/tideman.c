// Program that runs a Tideman election.

#include <stdio.h>
#include "cs50.h"

#define MAXCANDIDATES 9
#define MINCANDIDATES 2

int main(int argc, char const *argv[])
{
    string name;

    name = get_string("What's your name?\n");
    printf("Hello %s", name);

    return 0;
}
