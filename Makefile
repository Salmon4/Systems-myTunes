all: linkedList.o main.o
	gcc -o program linkedList.o main.o

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c

main.o: main.c linkedList.h
	gcc -c main.c

run:
	./program

clean:
	rm *.o
	rm *~
