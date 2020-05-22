// Program that implements a substitution cipher.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool validcommandline (int *argc, char const argv[27]);
void userinputtext (char text[1024]);
void textsubstitution (char text[1024], char key[27]);

// Start of the function main
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

    userinputtext(text);

    textsubstitution (text, key);

    return 0;
}

// Validates the command line Arguments
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

// Gets the text to encrypt from the user
void userinputtext (char text[1024])
{
    int i;

    for (i = 0; i < 1024; i++)
    {
        text[i] = 0;
    }

    printf("Plaintext: ");
    fgets(text, 1024, stdin);
}

// Applies cipher substitution and prints
void textsubstitution (char text[1024], char key[27])
{
    int i, j, k, temp;
    char cipher[1024];
    char alphabetlow[26];
    char alphabetup[26];

    for (i = 0; i < 1024; i++)
    {
        cipher[i] = 0;
    }
    for (i = 0, j = 65, k = 97; i < 26; i++, j++, k++)
    {
        alphabetup[i] = j;
        alphabetlow[i] = k;
    }

    i = 0;
    while (text[i] != 0)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            for (j = 0; j < 26; j++)
            {
                if (text[i] == alphabetup[j])
                {
                    cipher[i] = key[j];
                    cipher[i] = toupper(cipher[i]);
                }
            }
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            for (j = 0; j < 26; j++)
            {
                if (text[i] == alphabetlow[j])
                {
                    cipher[i] = key[j];
                    cipher[i] = tolower(cipher[i]);
                }
            }
        }
        else
        {
            cipher[i] = text[i];
        }
        i++;
    }

    printf("Ciphertext: %s\n", cipher);
}
