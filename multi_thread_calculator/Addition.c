#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  /* Extract numbers from the two dimensional array 'argv' and convert them to integers.
   * Perform addition on two numbers. 
   * Print the name of the program along with the process Id.
   * return status following the scheme given in the detailed assignment.
   */

  printf("Addition: Child Process [%d] \n", getpid());
  int sum = 0;
  for (int i = 1; i < argc; i++)
  {
    sum += atoi(argv[i]);
  }
  if (sum > 0)
  {
    return (1);
  }
  else if (sum < 0)
  {
    return (2);
  }
  else if (sum == 0)
  {
    return (0);
  }
  else
  {
    return (3);
  }
}
