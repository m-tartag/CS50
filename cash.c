// mario level maker
#include <cs50.h>

#include <stdio.h>

int main(void)
{
    float input;

    do
    {
        input = get_float("%s", "Submit: \n");
        printf("%f", input);
        printf("\n");
    } while (input < 0);
}