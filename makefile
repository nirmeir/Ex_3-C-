CC=gcc
FLAGS= -Wall -g

all: stringProg ex3

ex3: libex3.a

libex3.a: my_ex3.o 
	ar -rcs libex3.a my_ex3.o


stringProg: main.o libex3.a
	$(CC) $(FLAGS) main.o libex3.a -o stringProg

main.o: main.c my_ex3.h
	$(CC) $(FLAGS) -c main.c

my_ex3.o:my_ex3.c  my_ex3.h
	$(CC) $(FLAGS) -c my_ex3.c



.PHONY: clean all

clean:
	rm -f *.o *.a stringProg