# List of files
C_SRCS = Starter.c Addition.c Subtraction.c Multiplication.c Division.c FileReader.c
C_OBJS = Starter.o Addition.o Subtraction.o Multiplication.o Division.o FileReader.o
#C_HEADERS
OBJS = ${C_OBJS}
EXE = Starter
EXE1 = Addition
EXE2 = Subtraction
EXE3 = Multiplication
EXE4 = Division
EXE5 = FileReader
name = AlyAmmarHW3.tar

#Compiler and loader commands and flags
# -g : generates default debug info.
# -Wall: enables all compiler warnings
# -c: compiles source files without linking.
# -I: Include directory of header files.
GCC = gcc -lrt
GCC_FLAGS = -std=gnu99 -g  -Wall -c -I -lrt.
LD_FLAGS = -std=gnu99 -g  -Wall -I -lrt.

#Compile .c files to .o files
.c.o:
	$(GCC) $(GCC_FLAGS) $<
#Target is the executable
build: Starter Addition Subtraction Multiplication Division FileReader
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
FileReader: FileReader.o
	$(GCC) $(LD_FLAGS) FileReader.o -o $(EXE5)

#Recompile C objects if headers change
$(C_OBJS): ${C_HEADERS}

#Clean up the directory
clean:
	rm -f *.o *~ $(EXE) $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5)
package:
	tar -cvzf $(name) *.c *.txt Makefile
