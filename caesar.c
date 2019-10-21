#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[1])
{
    // Error if more than 1 key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Validates input is digits only
    for (int i = 0, n = strlen(argv[1]); i < n; ++i)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // converts string to int
            int k = atoi(argv[1]);
            // plaintext input
            string p = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int j = 0, pl = strlen(p); j < pl; j++)
            {
                if (isupper(p[j])) //If the character is uppercase it switches to the new uppercase
                {
                    printf("%c", (((p[j] + k) - 65) % 26) + 65);
                }
                else if (islower(p[j])) //If the character is lowercase it switches it to the new lowercase
                {
                    printf("%c", (((p[j] + k) - 97) % 26) + 97);
                }
                else //If the character is not a letter, it just prints it
                {
                    printf("%c", p[j]);
                }
            }
            printf("\n");

            return 0;
        }
    }
}