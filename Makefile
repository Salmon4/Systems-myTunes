all: main.o library.o linkedList.o
	gcc -o program main.o library.o linkedList.o

main.o: main.c library.h
	gcc -c main.c

library.o: library.c library.h linkedList.h
	gcc -c library.c

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c

run:
	./program

clean:
	rm *.o
	rm *~
