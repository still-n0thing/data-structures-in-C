CC = gcc
CFLAG = -std=c17 -Wall

Deque.o: Deque.h Deque.c 
	$(CC) $(CFLAG) -c Deque.c

libDeque.a: Deque.o
	ar -r libDeque.a Deque.o

Vector.o: Vector.h Vector.c 
	$(CC) $(CFLAG) -c Vector.c

libVector.a: Vector.o
	ar -r libVector.a Vector.o

main: main.c libVector.a
	$(CC) $(CFLAG) -L. main.c -lVector -o main.out

clean: 
	rm Deque.o libDeque.a Vector.o libVector.a main.out
