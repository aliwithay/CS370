CC=gcc
FILES=Starter.c Processor.c
OUT_EXE = Starter
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
clean:
	rm -f $(OUT_EXE)
package:
	tar --ignore-failed-read --warning=no-failed-read -cvzf $(name) *.c *.h *.txt Makefile
