CC=gcc
PP=g++
CFLAGS=-Wall

all: vm.cpp Front.cpp vm.h operands.h
	$(PP) $(CFLAGS) -c *.cpp
	$(CC) $(CFLAGS) -c *.c
	$(PP) -o hydro vm.o Front.o Table.o Scheduler.o Parser.o
	sudo mv hydro /usr/bin
	rm -f *.o


clean:
	rm -f hydro *.o

completeclean:
	rm -f hydro *.o
	sudo rm -f /usr/bin/hydro

test: hydro
	hydro -R tests/test.txt