README
======

This package includes the following files.

|-- Starter.c [This is the driver program which will be used to create a pipe, fork the FileReader, pass pipe fd to FileReader, parse the sets of operations and pair of numbers. Creates a shared memory for each set of operations, and 
|-- forks corresponding mathematical process in parallel, and waits for all of them to complete and displays the result in the right format.

|-- Addition.c [Performs addition operation on two numbers passed as an argument to it. Writes the name of the operation, the pair of numbers and the result into the shared memory, whose fd is given by Starter. Should be invoked by the 
|-- child processes only.]

|-- Subtraction.c [Performs subtraction operation on two numbers passed as an argument to it. Writes the name of the operation, the pair of numbers and the result into the shared memory, whose fd is given by Starter. Should be invoked 
|-- by the child processes only.]

|-- Multiplication.c [Performs multiplication operation on two numbers passed as an argument to it. Writes the name of the operation, the pair of numbers and the result into the shared memory, whose fd is given by Starter. Should be 
|-- invoked by the child processes only.]

|-- Division.c [Performs division operation on two numbers passed as an argument to it. Writes the name of the operation, the pair of numbers and the result into the shared memory, whose fd is given by Starter. Should be invoked by the 
|-- child processes only.]

|-- Makefile [For compiling, cleaning and taring].

|-- README.txt [This file]

|-- FileReader.c [Reads the content from the file whose name is received from the Starter and writes the content on to the pipe whose write end file descriptor is recieved from the Starter too.Should be invoked by the child processes 
|-- only.]


Questions:

1. What does pipe( ) do and what does it return?  (2 points)

Answer:




2. Name the function used to open a shared memory object? What are the possible oflag values. Give just a one-line description of each of the oflags value. (3 points).

Answer:

