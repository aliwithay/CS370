#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

   /* Skeleton Code
     * Open file whose name maybe provided as command line argument. If name is not provided open "numbers.txt"
     * Check if the file opened successfully. If not print the statement "File opening has failed. Ending program." and then exit the program.
     * Extract two integers from the file
     * Assume that there are only two numbers separated by space in a single line.
     * Close the file


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
          if status is 1 replace blank by "Result Positive".
          if status is 2 replace blank by "Result Negative".
          if status is 0 replace blank by "Result Zero".
          if status is 3 replace blank by "Result Undefined".
  */
   if (argc == 1)
   {
      char a[12];
      char b[12];
      FILE *in;
      in = fopen("numbers_1.txt", "r");
      if (in == NULL)
      {
         fprintf(stderr, "Can't open input file 'numbers.txt'!\n");
         return 1;
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
   return 0;
}
