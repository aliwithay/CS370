#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    /* Extract numbers from the two dimensional array 'argv' and convert them to integers.
   * Perform multiplication on two numbers. 
   * Print the name of the program along with the process Id.
   * return status following the scheme given in the detailed assignment.
  */
    printf("Multiplication: Child Process [%d]\n", getpid());
    int pro = 1;
    for (int i = 1; i < argc; i++)
    {
        pro *= atoi(argv[i]);
    }
    if (pro > 0)
    {
        exit(1);
    }
    else if (pro < 0)
    {
        exit(2);
    }
    else if (pro == 0)
    {
        exit(0);
    }
    else
    {
        exit(3);
    }
}
