// Program prints hello NAME

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

char *name = malloc(30);

    printf("Welcome, what is your name?: ");
    scanf("%s", name);

    printf("Hello %s", name);

    free(name);
    return 0;
}
