## Compiler directives
CC := gcc
CFLAGS := -g -std=c17 -Wall -Wextra -Werror -pedantic -Wsign-conversion
LIBFLGS := -lm

## User files
exec = calculator-app
obj_files = arithmetic.o main.o

## Main rules
$(exec): $(obj_files)
	$(CC) $^ -o $@ $(LIBFLAGS)

main.o: arithmetic.h
arithmetic.c: arithmetic.h


.DEFAULT_GOAL := run
.PHONY: run clean
run: $(exec)
	./$(exec)

clean:
	-rm -r $(exec) $(obj_files)
