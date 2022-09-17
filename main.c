/*
    main.c
*/

#ifndef _MAIN_C
#define _MAIN_C

#include <stdio.h>
#include "mymalloc.c"

void main() {
    node_t *ptr1 = mymalloc(100);
    node_t *ptr2 = mymalloc(100);
    node_t *ptr3 = mymalloc(100);

    myfree(ptr3);
    myfree(ptr2);
    myfree(ptr1);

}

#endif
