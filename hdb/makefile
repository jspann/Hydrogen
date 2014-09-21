CC=gcc
PP=g++
CFLAGS=-Wall

all:
	$(CC) $(CFLAGS) -c *.c
	$(CC) -o hdb *.o
	rm -f *.o


clean:
	rm -f hdb *.o

test: hdb
	hdb ../Tests/Test-1.hydro