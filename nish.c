

#include <stdio.h>
#include <stdlib.h>

typedef struct __node_t {
    size_t size;
    struct __node_t *next;
} node_t;

typedef struct __header_t{
    size_t size;
} header_t;


node_t *search(node_t *head, size_t size) {
    node_t *curr = head;
    size_t header_t_size = sizeof(header_t);
    while(curr != NULL) {
        if(curr->size  >= size + header_t_size) {
            return  curr;
        }
        curr = curr->next;
    }
    return curr;
}

int main()
{

    size_t heapsize = 100;
    node_t *head= (node_t*) malloc(heapsize);
    head->size = heapsize;
    head->next = NULL;

    printf("%d %d\n", head, head->size);

    /* node_t *next = (node_t*) malloc(200); */
    /* next->size = 200; */
    /* next->next = NULL; */

    /* head->next = next; */

    size_t size=50;
    node_t *block = search(head, size);
    /* printf("%d\n", next); */
    /* printf("%d %d\n", block, block->size); */

    size_t required_size = size + sizeof(header_t);
    size_t rem_size = block->size - required_size;


    //header_t *ret = (header_t*)((void*)block-sizeof(header_t));
    header_t *ret = (header_t*)block;
    ret->size = size;

    ret = (void*) ret + sizeof(header_t);

    // allocate a new block using rem_size
    node_t *new_block = (node_t*)((void*)block + required_size);
    new_block->size = rem_size;

    if(block == head) {
        new_block->next = head->next;
        head = new_block;
    } else {
        previous(block)->next = new_block;
        new_block->next = block->next;
    }


    node_t *ptr = .a.sdfla;

    freeptr = (void*) ret  - sizeof(header_t);
    freeptr = (header_t*) ret-1;
    
    total_new_size = freeptr->size + sizeof(header_t);
    node_t *newfree = (node_t*) freeptr;
    newfree->size = total_new_size;

    return 0;
}
