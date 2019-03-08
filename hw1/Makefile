CC=gcc
FILES=Starter.c Processor.c
OUT_EXE = Starter
assignment = Aly-Ammar-HW1
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
clean:
	rm -f $(OUT_EXE)
package:
	tar -cv $(MAKEFILE_LIST) Starter.c Processor.c Processor.h  Makefile README.txt >$(assignment).tar
