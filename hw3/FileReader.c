#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int write_fd = atoi(argv[2]);
    int count = 0;
    FILE *in;
    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        fprintf(stderr, "Can't open input file 'numbers.txt'!\n");
        return 0;
    }
    char str[50];
    while (fgets(str, 50, in) != NULL) {
        if(str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = ' ';
        }
        write(write_fd, str, strlen(str));
        count++;
    }
    write(write_fd, "\0", 2);
    return count;
}
