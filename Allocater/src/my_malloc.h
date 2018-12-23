#ifndef __MY_MALLOC_H
#define __MY_MALLOC_H
#include <stdlib.h>

// Some important constants.
#define HEAP_SIZE 4096
#define MAGIC 0xDEADBEEF

// This struct is used as the header of an allocated block.
typedef struct __header_t {
  size_t size;          // the number of bytes of allocated memory
  unsigned int magic;   // the magic number used to identify a valid allocated block
} header_t;

// This struct is used for the free list.
typedef struct __node_t {
  size_t size;            // the number of bytes available in this free block
  struct __node_t *next;  // a pointer to the next free list node
} node_t;

// This is the primary interface.
void *my_malloc(size_t);
void my_free(void *);

// We expose these functions for testing purposes.
void reset_heap();
size_t available_memory();
int number_of_free_nodes();
void print_free_list();
void find_free(size_t size, node_t **found, node_t **previous);
void split(size_t size, node_t **previous, node_t **free_block, header_t **allocated);
void coalesce(node_t *free_block);
  
#endif
