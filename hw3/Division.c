#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    /* Extract numbers from the two dimensional array 'argv' and convert them to integers.
   * Perform division on two numbers. 
   * Print the name of the program along with the process Id.
   * return status following the scheme given in the detailed assignment.
  */
    printf("Division: Child Process [%d]\n", getpid());
    int quo = atoi(argv[1]);
    for (int i = 2; i < argc - 1; i++)
    {
        quo /= atoi(argv[i]);
    }
    if (quo > 0)
    {
        exit(1);
    }
    else if (quo < 0)
    {
        exit(2);
    }
    else if (quo == 0)
    {
        exit(0);
    }
    else
    {
        exit(3);
    }
}
