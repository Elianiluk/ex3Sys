all:nodelist

nodelist: main.o StrList.o
	gcc -Wall main.o StrList.o -o nodelist
main.o: main.c StrList.h
	gcc -Wall -c main.c
StrList.o: StrList.c StrList.h
	gcc -Wall -c StrList.c

.PHONY: clean all

clean:
	rm *.o nodelist	