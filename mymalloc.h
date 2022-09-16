/*
    mymalloc.h
*/

#ifndef _MYMALLOC_H
#define _MYMALLOC_H

typedef struct {
    int size;
    int magic;
} header_t;

typedef struct __node_t {
    int size;
    struct __node_t *next;
} node_t;

node_t *initializeMemory ();

void *mymalloc (int size);

void myfree(void *ptr);

node_t *search(node_t *head, int size);

#endif