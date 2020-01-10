README
======

This package includes the following files.

|-- Starter.c [This is the driver program which will be used to open and read the file and also to invoke the child processes. Skeleton provided.]
|-- Addition.c [Performs addition operation on two numbers passed as an argument to it. Should be invoked by the child processes only. Skeleton provided.]
|-- Subtraction.c [Performs subtraction. Not provided, you need to come up on your own.]
|-- Multiplication.c [Performs multiplication. Not provided, you need to come up on your own.]
|-- Division.c [Performs division. Not provided, you need to come up on your own.]
|-- Makefile [For compiling and cleaning. Not provided, you need to come up on your own.].
|-- README.txt [This file]


Questions: One point each.

1. WEXITSTATUS consists of how many least significant bits of the status? 
Answer:8

2. Which header file has to be included to use the WEXITSTATUS? 
Answer:sys/wait.h

3. What is the return value for the fork() in a child process? 
Answer:0

4. Give a reason for the fork() to fail? 
Answer:Not enough resources available

5. Linear processing is when only one of the child processes is running at one time, and parallel processing is when more than one child process can be running at the same time.
   In the program written by you, are we following a linear processing or a parallel processing with respect to a child?  - 1 point
Answer:The process is linear since the system has to wait for each process to finish before starting a new process.
