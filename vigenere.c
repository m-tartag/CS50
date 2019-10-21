// Vigenere
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // validate input (need 2)
    if (argc != 2)
    {
        printf("Two arguments required.\n");

        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Input must be alphabetic.\n");

                return 1;
            }
        }
    }

    // store key as string

    string k = argv[1];
    int kLen = strlen(k);

    // Get text to encode

    string p = get_string("Input string\n");

    // Loop through text
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        // Get key for this letter
        int letterKey = tolower(k[j % kLen]) - 'a';

        // Keep case of letter
        if (isupper(p[i]))
        {
            printf("%c", 'A' + (p[i] - 'A' + letterKey) % 26);

            // increment j
            j++;
        }
        else if (islower(p[i]))
        {
            printf("%c", 'a' + (p[i] - 'a' + letterKey) % 26);
            j++;
        }
        else
        {
            // return unchanged
            printf("%c", p[i]);
        }
    }

    printf("\n");

    return 0;
}