#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

//This is the driver program which is used to create a pipe, fork the FileReader, pass pipe fd to FileReader, parse the sets of operations and pair of numbers. Creates a shared memory for each set of operations, and forks corresponding mathematical process in parallel, and waits for all of them to complete and displays the result in the right format.

int main(int argc, char **argv)
{
    //Check  for Usage.
    if (argc > 2) {
        printf("Too many arguments. \nUsage: Starter [NUMBER FILE] \nNumber file optional (Default: numbers.txt)\n"); 
    }
    int numOp;
    //Set default file.
    char *fileName = "numbers.txt";
    //Check for alternate numbers file.
    if (argc == 2)
    {
        fileName = argv[1];
    }
    //Create pipe.
    int fd[2];
    int result = pipe(fd);
    if (result == -1)
    {
        int errNum = errno;
        printf("[Starter]: Pipe creation failed! %s.\n", strerror(errNum));
        return 1;
    }
    //put pipe write end address to buf.
    char buf[200];
    sprintf(buf, "%i", fd[1]);
    //fork to FileReader.
    int pid = fork();
    if (pid == 0)
    {
        //Close read end of pipe and then call FileReader which would write to pipe.
        close(fd[0]);
        execlp("./FileReader", "FileReader", fileName, buf, NULL);
    }
    else if (pid > 0)
    {
        //Wait for FileReader to return.
        printf("Starter: forked process with ID [%i] \n", pid);
        printf("Starter: Pipe read end FD %i and pipe writer end FD %i.\n", fd[0], fd[1]);
        printf("Starter: waiting for process [%i] \n", pid);
        int waitStatus;
        wait(&waitStatus);
        //Get number of operations from FileReader as return value.
        int result = WEXITSTATUS(waitStatus);
        numOp = result;
        //Check for errors reported by FileReader.
        if (result == 0)
        {
            return 1;
        }
        printf("Starter: Child proces [%i] returned %d \n\n", pid, result);
    }
    else
    {
        //Produce error if forking fails.
        int errNum = errno;
        printf("Starter: Creating process ReadFile failed due to %s. Exiting \n", strerror(errNum));
        return 2;
    }
    //close write end of pipe to allow for reading.
    close(fd[1]);
    char r[256] = "";
    read(fd[0], r, sizeof(r)) ;             //r contains contents of pipe.
    close(fd[0]);                           //close read end of pipe as well.
    printf("Operations are %s\n\n", r);
    char a[12];
    char b[12];
    char operation[50];
    int i = 0;
    char* data = r;
    int offset = 0;
    int j = 0;
    int cpid[numOp];
    void *shmPtr[numOp];
    //read the contents of pipe in data (pointer to r) for the pattern, operation a b.
    while(sscanf(data,"%s %s %s %n", operation, a, b, &offset) == 3)
    {
        //offset data to end of the first read.
        data += offset;
        //create shared memory name.
        char s[10];
        sprintf(s, "%d", i++);
        char memName[12] = "Shared_mem";
        strcat(memName, s);
        //create shared memory, set its size and create a void pointer to the address.
        int shm_fd = shm_open(memName, O_CREAT | O_RDWR, 0666);
        if (shm_fd == -1)
        {
            int errNum = errno;
            printf("Starter: Shared memory creation failed. %s!\n", strerror(errNum));
            return 3;
        }
        int size = 256;
        int result = ftruncate(shm_fd, size);
        if (result == -1)
        {
            int errNum = errno;
            printf("Starter: Shared memory truncation failed. %s.\n", strerror(errNum));
            return 3;
        }
        shmPtr[j] = (int *)mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);
        //for for mathematical operations.
        cpid[j] = fork();
        if (cpid[j] == 0)
        {
            execlp(operation, operation, a, b, memName, NULL);
        }
        else if (cpid[j] > 0)
        {
            printf("Starter: Forked process [%i] for %s operation.\n", cpid[j], operation);
            printf("Starter: Name of shared memory is %s and FD is %d.\n", memName, shm_fd);
            printf("Starter: waiting for process [%i].\n\n", cpid[j]);
            j++;
        }
        else if (cpid[j] == -1)
        {
            //Produce error if forking fails.
            printf("Starter: Child process creation failed. Exiting \n");
            continue;
        }
    }
    for (int i = 0; i < numOp; i++) {
        char answer[50];
        char s[10];
        sprintf(s, "%d", i);
        char memName[12] = "Shared_mem";
        strcat(memName, s);
        int waitstatus;
        int returnpid = waitpid(cpid[i], &waitstatus, WCONTINUED);               //wait for pid to return.
        sscanf(shmPtr[i], "%s %s %s %s", operation, a, b, answer);              //read the shared memory and extract operation a b and answer.
        //print the output to stdout.
        printf("Starter: Child process [%i] of type %s operated on %s and %s and returned %s.\n\n", returnpid, operation, a, b, answer);
        shm_unlink(memName);
    }
}
