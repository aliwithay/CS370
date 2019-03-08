#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

int main(int argc, char **argv)
{
    /* Extract numbers from the two dimensional array 'argv' and convert them to integers.
   * Perform division on two numbers. 
   * Print the name of the program along with the process Id.
   * return status following the scheme given in the detailed assignment.
  */
    printf("Division: Child Process [%d]\n\n", getpid());
    int quo = atoi(argv[1]);
    for (int i = 2; i < argc - 1; i++)
    {
        quo /= atoi(argv[i]);
    }
int shm_fd = shm_open(argv[3], O_CREAT | O_RDWR, 0666);
if (shm_fd == -1)
{
        int errNum = errno;
        printf("Addition: Shared memory creation failed. %s!\n", strerror(errNum));
        return 3;
}
int size = 256;
void *shmPtr = (int *)mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);
sprintf(shmPtr, "%d", quo);
shm_unlink(argv[3]);
return 0;
}
