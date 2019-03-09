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
* Perform addition on two numbers. 
* Print the name of the program along with the process Id.
* return status following the scheme given in the detailed assignment.
*/

    printf("Addition: Child Process [%d] \n\n", getpid());
    int sum = 0;
    void *shmPtr;
    for (int i = 1; i < argc - 1; i++)
    {
        sum += atoi(argv[i]);
    }
    int shm_fd = shm_open(argv[3], O_CREAT | O_RDWR, 066);
    if (shm_fd == -1)
    {
        int errNum = errno;
        printf("Addition: Shared memory creation failed. %s!\n", strerror(errNum));
        return 3;
    }
    int size = 256;
    shmPtr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    char *operation = argv[0];
    char *a = argv[1];
    char *b = argv[2];
    sprintf(shmPtr, "%s %s %s %d\n", operation, a, b, sum);
    shm_unlink(argv[3]);
    return 0;
}
