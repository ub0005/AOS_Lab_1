#This is a makefile
CC      = gcc
CFLAGS  = -c
RM      = rm -rf

default: all

all: mymalloc mymallocinterface mylibrary main clean

mymalloc:
	$(CC) $(CFLAGS) mymalloc.c
mymallocinterface:
	$(CC) $(CFALGS) mymalloc.h
mylibrary:
	ar rcs my_library.a mymalloc.o mymalloc.h.gch
main:
	$(CC) -o main main.c my_library.a
clean:
	$(RM) my_library.a mymalloc.o mymalloc.h.gch