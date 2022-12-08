#include <stdio.h>
#include <time.h>

int rand(void);
void srand(unsigned int seed);

int main()
{
  srand(time(NULL));

  int credits = 5000;
  int first_num = -1;
  int second_num = -1;
  int third_num = -1;
  int n;

  while (1)
  {
    printf("\n\n\tCurrent number of credits: %d", credits);
    printf("\n\tPRESS ENTER TO PLAY (100 credits)");
    getchar();
    first_num = rand() % 8;
    second_num = rand() % 8;
    third_num = rand() % 8;
    printf("\n\n\t%d   %d   %d", first_num, second_num, third_num);
    if (first_num == second_num && second_num == third_num)
    {
      if (first_num == 6)
      {
        printf("\n\n\tUnlucky, you have lost 500 credits :(\n\tCombination: 6  6  6");
        credits -= 500;
      }
      else
      {
        if (first_num == 7)
        {
          printf("\n\n\tJACKPOT!!!\n");
          return 1;
        }
        else
        {
          if (first_num < 5)
          {
            printf("\n\n\tYou are lucky, you have won 500 credits!!!\n\tCombination: %d  %d  %d", first_num, second_num, third_num);
            credits += 500;
          }
          else
          {
            if (first_num == 5)
            {
              printf("\n\n\tYou are lucky, you have won 800 credits!!!\n\tCombination: 5  5  5");
              credits += 800;
            }
          }
        }
      }
    }
    else
    {
      if (first_num == second_num && first_num > 4)
      {
        if (first_num == 5)
        {
          printf("\n\n\tYou are lucky, you have won 400 credits!!!\n\tCombination: 5  5  X");
          credits += 400;
        }
        else
        {
          if (first_num == 7)
          {
            printf("\n\n\tYou almost got it! You have won 1000 credits!!!\n\tCombination: 7  7  X");
            credits += 1000;
          }
          else
          {
            if (first_num == 6)
            {
              printf("\n\n\tUnlucky, you have not won anything, try again :(");
            }
          }
        }
      }
      else
      {
        if (first_num == 5 || first_num == 7)
        {
          if (first_num == 5)
          {
            printf("\n\n\tYou are lucky, you have won 200 credits!!!\n\tCombination: 5  X  X");
            credits += 200;
          }
          else
          {
            printf("\n\n\tYou are lucky, you have won 300 credits!!!\n\tCombination: 7  X  X");
            credits += 300;
          }
        }
        else
        {
          printf("\n\n\tUnlucky, you have not won anything, try again :(");
        }
      }
    }
    credits -= 100;
    if (credits < 1)
    {
      printf("\n\n\tBad news, you have spent all credits, game over :(\n");
      getchar();
      return 0;
    }
    printf("\n");
  }
}
