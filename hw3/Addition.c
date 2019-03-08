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
    for (int i = 1; i < argc - 1; i++)
    {
        sum += atoi(argv[i]);
    }
    int shm_fd = shm_open(argv[3], O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        int errNum = errno;
        printf("Addition: Shared memory creation failed. %s!\n", strerror(errNum));
        return 3;
    }
    int size = 256;
    int result = ftruncate(shm_fd, size);
    if (result == -1)
    {
        int errNum = errno;
        printf("Addition: Shared memory truncation failed. %s\n", strerror(errNum));
        return 3;
    }
    void *shmPtr = (int *)mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);
    printf("returns0");
    fflush(stdout);
    char *operation = argv[0];
    char *a = argv[1];
    char *b = argv[2];
    sprintf(shmPtr, "%s %s %s %d\n", operation, a, b, sum);
    printf("returns");
    fflush(stdout);
    shm_unlink(argv[3]);
    return 0;
}
