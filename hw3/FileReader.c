#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    write_fd = atoi(argv[argc - 1]);
    FILE *in;
    in = fopen(argv[0], "r");
    if (in == NULL)
    {
        fprintf(stderr, "Can't open input file 'numbers.txt'!\n");
        return 1;
    }
    write(write_fd, in, sizeof(in));
    return 0;
}