/*
    mymalloc.c
*/

#ifndef _MYMALLOC_C
#define _MYMALLOC_C

#include <stdio.h>
#include <sys/mman.h>

#include "mymalloc.h"

node_t *head  = NULL;

node_t *initializeMemory () {
    // mmap() returns a pointer to a chunk of free space
    node_t *head = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
    head->size = 4096 - sizeof(node_t);
    head->next = NULL;
    return head;
}

void *mymalloc (int size) {
    // Add size of node_t to the user input size
    int actualNeededSize = size + sizeof(header_t);
    if (head == NULL) {
        // if the head is NULL, allocate a chunk of memory using mmap
        head = initializeMemory();
    } else {
        node_t *block = search(head, actualNeededSize);
        size_t rem_size = block->size - actualNeededSize;

        header_t *ret = (header_t*)block;
        ret->size = size;
        ret = (void*) ret + sizeof(header_t);


        // allocate a new block using rem_size
        node_t *new_block = (node_t*)((void*)block + actualNeededSize);
        new_block->size = rem_size;

        if(block == head) {
            new_block->next = head->next;
            head = new_block;
        } else {
            //previous(block)->next = new_block;
            new_block->next = block->next;
        }
        return ret;
    }
    
}

void myfree(void *ptr) {
    header_t *freeptr = (header_t *) ptr - 1;

    size_t total_new_size = freeptr->size + sizeof(header_t);
    node_t *newfree = (node_t*) freeptr;
    newfree->size = total_new_size;
    newfree->next = head->next;
}

node_t *search(node_t *head, int size) {
    node_t *curr = head;
    size_t header_t_size = sizeof(header_t);
    while(curr != NULL) {
        if(curr->size  >= size) {
            return  curr;
        }
        curr = curr->next;
    }
    return curr;
}

#endif




