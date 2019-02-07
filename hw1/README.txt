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
True

2. Not freeing the allocated memory throws a compilation error? True/false
flase

3. In which header file is malloc defined in?  ______ 
stdlib

4. In makefile the default target is always the ______ target. 
build

5. Which symbol/sign is used in a makefile to use the value stored in particular variable? ______ 
$

D. Valgrind output for memory leak:

==149== Memcheck, a memory error detector
==149== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==149== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==149== Command: ./Starter 1256
==149==
==149== error calling PR_SET_PTRACER, vgdb might block
[Starter]: With seed: 1256
[Processor]: Number of iterations is 113
[Processor]: Largest array size is 796
[Starter]: Running ratio: 1.014324

==149==
==149== HEAP SUMMARY:
==149==     in use at exit: 67,696 bytes in 113 blocks
==149==   total heap usage: 114 allocs, 1 frees, 68,208 bytes allocated
==149==
==149== LEAK SUMMARY:
==149==    definitely lost: 67,696 bytes in 113 blocks
==149==    indirectly lost: 0 bytes in 0 blocks
==149==      possibly lost: 0 bytes in 0 blocks
==149==    still reachable: 0 bytes in 0 blocks
==149==         suppressed: 0 bytes in 0 blocks
==149== Rerun with --leak-check=full to see details of leaked memory
==149==
==149== For counts of detected and suppressed errors, rerun with: -v
==149== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)