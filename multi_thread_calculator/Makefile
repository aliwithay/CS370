# List of files
C_SRCS = Starter.c Addition.c Subtraction.c Multiplication.c Division.c
C_OBJS = Starter.o Addition.o Subtraction.o Multiplication.o Division.o
#C_HEADERS
OBJS = ${C_OBJS}
EXE = Starter
EXE1 = Addition
EXE2 = Subtraction
EXE3 = Multiplication
EXE4 = Division
name = AlyAmmarHW2.tar

#Compiler and loader commands and flags
# -g : generates default debug info.
# -Wall: enables all compiler warnings
# -c: compiles source files without linking.
# -I: Include directory of header files.
GCC = gcc
GCC_FLAGS = -std=c11 -g  -Wall -c -I.
LD_FLAGS = -std=c11 -g  -Wall -I.

#Compile .c files to .o files
.c.o:
	$(GCC) $(GCC_FLAGS) $<
#Target is the executable
build: Starter Addition Subtraction Multiplication Division
Starter: Starter.o
	$(GCC) $(LD_FLAGS) Starter.o -o $(EXE)
Addition: Addition.o
	$(GCC) $(LD_FLAGS) Addition.o -o $(EXE1)
Subtraction: Subtraction.o
	$(GCC) $(LD_FLAGS) Subtraction.o -o $(EXE2)
Multiplication: Multiplication.o
	$(GCC) $(LD_FLAGS) Multiplication.o -o $(EXE3)
Division: Division.o
	$(GCC) $(LD_FLAGS) Division.o -o $(EXE4)

#Recompile C objects if headers change
$(C_OBJS): ${C_HEADERS}

#Clean up the directory
clean:
	rm -f *.o *~ $(EXE) $(EXE1) $(EXE2) $(EXE3) $(EXE4)
package:
	tar -cvzf $(name) *.c *.txt Makefile
