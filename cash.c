// mario level maker
#include <cs50.h>

#include <stdio.h>

int main(void)
{
    float input;
    float penny, nickel, dime, quarter;

    penny = 0.01;
    nickel = 0.05;
    dime = 0.10;
    quarter = 0.25;

    do
    {
        input = get_float("%s", "Submit: \n");
        printf("%f", input);
        printf("\n");
    } while (input < 0)
}