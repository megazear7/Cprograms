%.o:%.c
	gcc -g -c -Wall -o $@ $<

all: lab2

lab2.o:lab2.c

lab2:lab2.o
	gcc -Wall -o lab2 lab2.o

clean:
	rm -f *.o lab2
