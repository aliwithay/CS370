README
======

A. This package includes the following files. In your own readme file, modify the information as needed.

|-- Starter.c [This is the driver program which will be used to invoke the get_running_ratio.]
|-- Processor.c [Skeleton version, in which you have to fill in the missing code.]
|-- Processor.h [Header file declaring the function exposed from Processor.c]
|-- README.txt [This file]


B. Use the provided makefile to compile the code and build the executable using the command 

systemprompt>  make

To remove the  executable files use

systemprompt>  make clean

To run the program use (assuming seed is 34) 

systemprompt> ./Starter 34

which will run the program and generate the outputs.

To tar all .c, .h, .txt files, use the command

systemprompt> make package name=<FirstName>-<LastName>-HW1.<tar>

where you have to pass your first name and last name.


C. Answer the following questions (1 point each, select/type the right answer).

1. Malloc takes the number of bytes to be allocated as the argument? True/false

2. Not freeing the allocated memory throws a compilation error? True/false

3. In which header file is malloc defined in?  ______  

4. In makefile the default target is always the ______ target. 

5. Which symbol/sign is used in a makefile to use the value stored in particular variable? ______ 