CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra -Wshadow -pedantic
LIGFLAGS = -lm

## User files 
obj_files = main.o sort.o
exec = sort.app
arg1 = 32
arg2 = 1

## main rules
$(exec): $(obj_files)
	$(CC) $^ -o $(exec) $(LIBFLAGS)

sort.o: sort.h
main.o: sort.h

## phony targets
.PHONY: run clean test
.DEFAULT_GOAL := run

run: $(exec)
	./$(exec) $(arg1) $(arg2)

clean:
	-rm -r $(obj_files) $(exec)
