#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    
    /* Skeleton Code
     * Open file whose name maybe provided as command line argument. If name is not provided open "numbers.txt"
     * Check if the file opened successfully. If not print the statement "File opening has failed. Ending program." and then exit the program.
     * Extract two integers from the file
     * Assume that there are only two numbers separated by space in a single line.
     * Close the file
     * 
     * 
     * Perform four operations (Addition, Subtraction, Multiplication, Division) using the following steps:
     * For each operation, fork a child process.
     * 1.If inside the Parent process display the following text
     *      "Starter: forked process with ID *child_process_id*."
     *      "Starter: waiting for process [*child_process_id*]."
     *   Use wait() to wait for the child process to complete the execution. Pass address of waitstatus as parameter to wait()
     *   Get the exit status of the child process using WEXITSTATUS() with the input parameter as waitstatus.
     *   See https://www.geeksforgeeks.org/wait-system-call-c/ for more details on usage/examples
     *   Print the following statement
     *      "Starter: Child process *child_process_id* returned *status*"
     * 2.If inside the Child process, invoke the corresponding operation program, *operation_file*.c using the function execlp
     *      See man exec or man execlp for more information on usage/paramaters
     * 3.If forking has failed, Print the following statement and exit the program.
     *      "Starter: Child Process Creation failed. Exiting."
     * Print the statement "Starter: Addition: _"
     * Print the statement "Starter: Subtraction: _"
     * Print the statement "Starter: Multiplication: _"
     * Print the statement "Starter: Division: _" where the blank is the status.
     *        if status is 1 replace blank by "Result Positive".
     *        if status is 2 replace blank by "Result Negative".
     *        if status is 0 replace blank by "Result Zero".
     *        if status is 3 replace blank by "Result Undefined".
     * if (argc == 1)
     * {
     *    char a[12];
     *    char b[12];
     *    FILE *in;
     *    in = fopen("numbers_1.txt", "r");
     *    if (in == NULL)
     *    {
     *        fprintf(stderr, "Can't open input file 'numbers.txt'!\n");
     *        return 1;
}
fscanf(in, "%s %s", a, b);
fclose(in);
//int sum, dif, pro, quo;
for (int i = 0; i < 4; i++)
{
int pid = fork();
if (pid == 0)
{
switch (i)
{
    case 0:
        execlp("./Addition", "Addition", a, b, NULL);
        break;
    case 1:
        execlp("./Subtraction", "Subtraction", a, b, NULL);
        break;
    case 2:
        execlp("./Multiplication", "Multiplication", a, b, NULL);
        break;
    case 3:
        execlp("./Division", "Division", a, b, NULL);
        break;
}
}
else if (pid > 0)
{
int waitstatus;
printf("Starter: forked process with ID %i \n", pid);
printf("Starter: waiting for process [%i] \n", pid);
wait(&waitstatus);
int result = WEXITSTATUS(waitstatus);
printf("Starter: Child proces %i returned %d \n", pid, result);
if (i == 0)
{
switch (result)
{
    case 0:
        printf("Starter: Addition: Result Zero\n");
        break;
    case 1:
        printf("Starter: Addition: Result Positive\n");
        break;
    case 2:
        printf("Starter: Addition: Result Negative\n");
        break;
    case 3:
        printf("Starter: Addition: Result Undefined\n");
        break;
}
}
else if (i == 1)
{
switch (result)
{
    case 0:
        printf("Starter: Subtraction: Result Zero\n");
        break;
    case 1:
        printf("Starter: Subtraction: Result Positive\n");
        break;
    case 2:
        printf("Starter: Subtraction: Result Negative\n");
        break;
    case 3:
        printf("Starter: Subtraction: Result Undefined\n");
        break;
}
}
else if (i == 2)
{
switch (result)
{
    case 0:
        printf("Starter: Multiplication: Result Zero\n");
        break;
    case 1:
        printf("Starter: Multiplication: Result Positive\n");
        break;
    case 2:
        printf("Starter: Multiplication: Result Negative\n");
        break;
    case 3:
        printf("Starter: Multiplication: Result Undefined\n");
        break;
}
}
else
{
switch (result)
{
    case 0:
        printf("Starter: Division: Result Zero\n");
        break;
    case 1:
        printf("Starter: Division: Result Positive\n");
        break;
    case 2:
        printf("Starter: Division: Result Negative\n");
        break;
    case 3:
        printf("Starter: Division: Result Undefined\n");
        break;
}
}
}
else if (pid == -1)
{
printf("Starter: Child process creation failed. Exiting \n");
}
}
}
*/
    int numOp;
    char *fileName = "numbers.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    int fd[2];
    int result = pipe(fd);
    if (result == -1)
    {
        int errNum = errno;
        printf("[Starter]: Pipe creation failed! %s.\n", strerror(errNum));
        return 1;
    }
    char buf[200];
    sprintf(buf, "%i", fd[1]);
    int pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        execlp("./FileReader", "FileReader", fileName, buf, NULL);
    }
    else if (pid > 0)
    {
        printf("Starter: forked process with ID [%i] \n", pid);
        printf("Starter: Pipe read end FD %i and pipe writer end FD %i.\n", fd[0], fd[1]);
        printf("Starter: waiting for process [%i] \n", pid);
        int waitStatus;
        wait(&waitStatus);
        int result = WEXITSTATUS(waitStatus);
        numOp = result;
        if (result == 0)
        {
            return 1;
        }
        printf("Starter: Child proces [%i] returned %d \n\n", pid, result);
    }
    else
    {
        int errNum = errno;
        printf("Starter: Creating process ReadFile failed due to %s. Exiting \n", strerror(errNum));
        return 2;
    }
    close(fd[1]);
    char r[256] = "";
    read(fd[0], r, sizeof(r)) ;
    close(fd[0]);
    printf("Operations are %s\n\n", r);
    char a[12];
    char b[12];
    char operation[50];
    int i = 0;
    char* data = r;
    int offset = 0;
    int j = 0;
    int cpid[numOp];
    void *shmPtr;
    while(sscanf(data,"%s %s %s %n", operation, a, b, &offset) == 3)
    {
        data += offset;
        char s[10];
        sprintf(s, "%d", i++);
        char memName[12] = "Shared_mem";
        strcat(memName, s);
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
            printf("Starter: Shared memory truncation failed. %s\n", strerror(errNum));
            return 3;
        }
        shmPtr = (int *)mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);
        cpid[j] = fork();
        if (cpid[j] == 0)
        {
            execlp(operation, operation, a, b, memName, NULL);
        }
        else if (cpid[j] > 0)
        {
            printf("Starter: Forked process [%i] for %s operation.\n", cpid[j], operation);
            printf("Starter: Name of shared memory is %s and FD is %i.\n", memName, shm_fd);
            printf("Starter: waiting for process [%i].\n\n", cpid[j]);
            j++;
        }
        else
        {
            printf("Starter: Child process creation failed. Exiting \n");
        }
    }
    for (int i = 0; i < numOp; i++) {
        char *operation, *a, *b;
        char s[10];
        sprintf(s, "%d", i);
        char memName[12] = "Shared_mem";
        strcat(memName, s);
        int waitstatus;
        int returnpid = waitpid(cpid[i], &waitstatus, WCONTINUED);
        char *res;
        sscanf(shmPtr, "%[^\n]", res);
        operation = strtok(res, " ");
        a = strtok(NULL, " ");
        b = strtok(NULL, " ");
        res = strtok(NULL, " ");
        printf("Starter: Child process [%i] of type %s operated on %s and %s and returned %s.\n\n", returnpid, operation, a, b, res);
        shm_unlink(memName);
    }
}
