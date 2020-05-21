// Implement a program that implements a substitution cipher.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool validcommandline (int *argc, char const argv[27]);

// Start function main
int main(int argc, char const *argv[])
{
    bool isvalid = true;
    char key[27], text[1024];

    isvalid = validcommandline(&argc, argv[1]);
    if (isvalid == false)
    {
        printf("\nUsage: ./substitution key of 26 characters\n\n");
        return 1;
    }

    strcpy(key, argv[1]);
    printf("Key is %s\n", key); // Test

    return 0;
}

// Validates Arguments
bool validcommandline (int *argc, char const argv[27])
{
    int i, j, temp;
    char tempkey[27];

    if (*argc != 2)
    {
        return false;
    }

    if (strlen(argv) != 26)
    {
        return false;
    }

    i = 0;
    while (i < 26)
    {
        temp = isalpha(argv[i]);
        if (temp == 0)
        {
            return false;
        }
        i++;
    }

    strcpy(tempkey, argv);
    for (i = 0; i < 26; i++)
    {
        tempkey[i] = tolower(tempkey[i]);
    }

    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (tempkey[i] == tempkey[j] && i != j)
            {
                return false;
            }
        }
    }

    return true;
}
