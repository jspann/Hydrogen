CC=gcc
PP=g++
CFLAGS=-Wall

all: vm.cpp Front.cpp vm.h
	$(PP) $(CFLAGS) -c *.cpp
	$(PP) -o hydro vm.o Front.o Table.o Scheduler.o Parser.o
	sudo mv hydro /usr/bin

clean:
	rm -f hydro *.o

completeclean:
	rm -f hydro *.o
	sudo rm -f /usr/bin/hydro

test: hydro
	hydro -R tests/test.txt