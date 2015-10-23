CC=gcc
PP=g++
CFLAGS=-Wall

all:
	$(PP) $(CFLAGS) -c stack.cpp
	$(PP) $(CFLAGS) -c register.cpp
	$(PP) $(CFLAGS) -c heap.cpp
	$(PP) $(CFLAGS) -c Front.cpp
	$(PP) $(CFLAGS) -c vm.cpp
	$(PP) -o hydro heap.o vm.o Front.o register.o stack.o
	sudo mv hydro /usr/bin
	rm -f *.o


clean:
	rm -f hydro *.o

completeclean:
	rm -f hydro *.o
	sudo rm -f /usr/bin/hydro

test: hydro
	hydro -R tests/test.txt