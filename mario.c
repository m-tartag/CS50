// mario level maker
#include <cs50.h>

#include <stdio.h>

int main(void)
{
  int input;
  do
  {
    input = get_int("%s", "Input 1-8: \n");
  } while (input < 1 || input > 8);

  for (int i = 1; i <= input; i++)
  {
    for (int j = input; j > i; j--)
    {
      printf(" ");
    }
    for (int k = 1; k <= i; k++)
    {
      printf("#");
    }
    printf("\n");
  }
}
