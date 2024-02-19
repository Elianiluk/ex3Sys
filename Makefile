all:StrList

StrList: main.o StrList.o
	gcc -Wall main.o StrList.o -o StrList
main.o: main.c StrList.h
	gcc -Wall -c main.c
StrList.o: StrList.c StrList.h
	gcc -Wall -c StrList.c

.PHONY: clean all

clean:
	rm *.o StrList	