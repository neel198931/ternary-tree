all:main linkedListTest dataTest

data.o: data.c data.h
	gcc -Wall -c -g data.c

linkedList.o: linkedList.h linkedList.c
	gcc -Wall -c -g linkedList.c

tree.o: tree.h tree.c
	gcc -Wall -c -g tree.c

main.o: main.c
	gcc -Wall -c -g main.c

main: data.o linkedList.o tree.o main.o
	gcc -Wall -g data.o linkedList.o tree.o main.o -o main

linkedListTest.o: linkedListTest.c
	gcc -Wall -g -c linkedListTest.c

linkedListTest: data.o linkedList.o linkedListTest.o
	gcc -Wall -g data.o linkedList.o linkedListTest.o -o linkedListTest

dataTest.o: dataTest.c
	gcc -Wall -g -c dataTest.c

dataTest: data.o dataTest.o
	gcc -Wall -g data.o dataTest.o -o dataTest

clean:
	rm *~ *.o main linkedListTest dataTest