#This is a makefile

RM	= rm -rf
	
default: all

all: mymalloc mylibrary main clean

mymalloc:
	gcc -c mymalloc.c

mylibrary:
	ar rcs libmymalloc.a mymalloc.o

main:
	gcc -g -I . main.c -L. -lmymalloc -o main 

clean:
	$(RM) libmymalloc.a mymalloc.o