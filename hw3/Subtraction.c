#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    /* Extract numbers from the two dimensional array 'argv' and convert them to integers.
   * Perform subtraction on two numbers. 
   * Print the name of the program along with the process Id.
   * return status following the scheme given in the detailed assignment.
  */
    printf("Subtraction: Child Process [%d]\n", getpid());
    int dif = atoi(argv[1]);
    for (int i = 2; i < argc - 1; i++)
    {
        dif -= atoi(argv[i]);
    }
    if (dif > 0)
    {
        return (1);
    }
    else if (dif < 0)
    {
        return (2);
    }
    else if (dif == 0)
    {
        return (0);
    }
    else
    {
        return (3);
    }
}
