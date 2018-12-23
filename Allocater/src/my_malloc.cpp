#include "my_malloc.h"
#include <assert.h>
#include <stdio.h>
#include <sys/mman.h>

// A pointer to the head of the free list.
node_t *head = NULL;

// The heap function returns the head pointer to the free list. If the heap
// has not been allocated yet (head is NULL) it will use mmap to allocate
// a page of memory from the OS and initialize the first free node.
node_t *heap() {
  if (head == NULL) {
    // This allocates the heap and initializes the head node.
    head = (node_t *)mmap(NULL, HEAP_SIZE, PROT_READ | PROT_WRITE,
                          MAP_ANON | MAP_PRIVATE, -1, 0);
    head->size = HEAP_SIZE - sizeof(node_t);
    head->next = NULL;
  }

  return head;
}

// Reallocates the heap.
void reset_heap() {
  if (head != NULL) {
    munmap(head, HEAP_SIZE);
    head = NULL;
    heap();
  }
}

// Returns a pointer to the head of the free list.
node_t *free_list() {
  return head;
}

// Calculates the amount of free memory available in the heap.
size_t available_memory() {
  size_t n = 0;
  node_t *p = heap();
  while (p != NULL) {
    n += p->size;
    p = p->next;
  }
  return n;
}

// Returns the number of nodes on the free list.
int number_of_free_nodes() {
  int count = 0;
  node_t *p = heap();
  while (p != NULL) {
    count++;
    p = p->next;
  }
  return count;
}

// Prints the free list. Useful for debugging purposes.
void print_free_list() {
  node_t *p = heap();
  while (p != NULL) {
    printf("Free(%zd)", p->size);
    p = p->next;
    if (p != NULL) {
      printf("->");
    }
  }
  printf("\n");
}

// Finds a node on the free list that has enough available memory to
// allocate to a calling program. This function uses the "first-fit"
// algorithm to locate a free node.
// 
// PARAMETERS:
// size - the number of bytes requested to allocate
//
// RETURNS:
// found - the node found on the free list with enough memory to allocate
// previous - the previous node to the found node
//
void find_free(size_t size, node_t **found, node_t **previous) {
	// TODO

node_t* curr = heap();
node_t* prev = NULL;

while(curr != NULL){
  size_t real_curr_size = curr->size + sizeof(node_t);

  if(real_curr_size >= (size + sizeof(header_t))){  //found free block
    *found = curr;
    *previous = prev;
    return;
  }

  else{
    curr = curr->next;

    if(prev == NULL) // curr was head
      prev = heap();

    else{
      prev = prev->next;
    }

  }

}
  *found = NULL;
  *previous = NULL;

}

// Splits a found free node to accommodate an allocation request.
//
// The job of this function is to take a given free_node found from
// `find_free` and split it according to the number of bytes to allocate.
// In doing so, it will adjust the size and next pointer of the `free_block`
// as well as the `previous` node to properly adjust the free list.
//
// PARAMETERS:
// size - the number of bytes requested to allocate
// previous - the previous node to the free block
// free_block - the node on the free list to allocate from
//
// RETURNS:
// allocated - an allocated block to be returned to the calling program
//  
void split(size_t size, node_t **previous, node_t **free_block, header_t **allocated) {
  assert(*free_block != NULL);

  node_t* original_fb = *free_block;

  size_t actual_size = size + sizeof(header_t);
  *free_block = (node_t*)(((char*)*free_block) + actual_size);

 

   if(*previous == NULL)
    head = *free_block;
  else
    (*previous)->next = *free_block;

   (*free_block)->next = original_fb ->next;
  (*free_block)->size = original_fb->size - size - sizeof(node_t);

  *allocated = (header_t*)original_fb;
  (*allocated)->size = size;
  (*allocated)->magic = MAGIC;

}



// Returns a pointer to a region of memory having at least the request `size` bytes.
//
// PARAMETERS:
// size - the number of bytes requested to allocate
//
// RETURNS:
// A void pointer to the region of allocated memory
//
void *my_malloc(size_t size) {
  // TODO

node_t* found;
node_t* prev;
header_t* allocated;

find_free(size, &found, &prev);
if( found == NULL)
  return NULL;

split(size, &prev, &found, &allocated);

return (void*)(((char*)allocated) + sizeof(header_t));

}

// Merges adjacent nodes on the free list to reduce external fragmentation.
//
// This function will only coalesce nodes starting with `free_block`. It will
// not handle coalescing of previous nodes (we don't have previous pointers!).
//
// PARAMETERS:
// free_block - the starting node on the free list to coalesce
//
void coalesce(node_t *free_block) {
  // TODO
  node_t* curr = free_block;

  while(curr != NULL){

    if(curr->next == NULL) //last node in the list      
      curr = curr->next;

    else{ //general case
      size_t block_size = curr->size + sizeof(node_t);

      void* current_address = (void*)curr;
      void* next_address = (void*)(curr->next);

      if(((char*)current_address) + block_size == next_address){
        //if two adjacent blocks share the same address:

        curr->size = curr->size + curr->next->size + sizeof(node_t);
        curr->next = curr->next->next;
      }
      else

          curr = curr->next;
    
    }

  }

}

// Frees a given region of memory back to the free list.
//
// PARAMETERS:
// allocated - a pointer to a region of memory previously allocated by my_malloc
//
void my_free(void *allocated) {
  //TODO

  header_t* header_allocated = (header_t*)((char*)allocated - sizeof(header_t));
  (header_allocated)->magic = MAGIC;
  assert(header_allocated->magic == MAGIC);
  
  node_t* node_t_alloc = (node_t*)header_allocated;
  node_t_alloc->size = header_allocated->size + sizeof(header_t) - sizeof(node_t);
  node_t_alloc->next = head;
  coalesce(node_t_alloc);
  head = node_t_alloc;

}


/*


This​ ​ function​ ​ is​ ​ relatively​ ​ easy​ ​ with​ ​ the​ ​ help​ ​ of​ ​ the​ coalesce​​ ​ 
function​ ​ above.​ ​ 

First,​ ​ cast​ ​ the​ ​ allocated
parameter​ ​ to​ ​ a ​ ​ header_t*​​ ​ type.​ ​ Remember,​ ​ you​ ​ need​ ​ to​ ​ 
adjust​ ​ the​ ​ pointer​ ​ that​ ​ is​ ​ given​ ​ by
sizeof(header_t)​​ ​ to​ ​ point​ ​ to​ ​ the​ ​ actual​ ​ start​ ​ of​ ​ the​ ​ allocated​ ​ 
block.​ ​ 

After​ ​ you​ ​ do​ ​ that​ ​ you​ ​ should​ ​ use​ assert
to​ ​ ensure​ ​ that​ ​ the​ ​ magic​​ ​ field​ ​ is​ ​ indeed​ ​ equal​ ​ to​ ​ MAGIC​ . ​ ​ 

Next,​ ​ you​ ​ simply​ ​ need​ ​ to​ ​ cast​ ​ the​ ​ header_t*​ ​ to​ ​ a
node_t*​ ​ and​ ​ set​ ​ the​ ​ size​ ​ to​ ​ the​ ​ size​ ​ of​ ​ bytes​ ​ we​ ​ are​ ​ freeing.​ ​

Lastly,​ ​ link​ ​ in​ ​ the​ ​ freed​ ​ node​ ​ into​ ​ the​ ​ free​ ​ list​ ​ by
making​ ​ this​ ​ newly​ ​ freed​ ​ node​ ​ the​ ​ start​ ​ of​ ​ the​ ​ heap​ ​ - ​ ​ don't​ ​
forget​ ​ to​ ​ assign​ ​ its​ ​ next​ ​ pointer​ ​ to​ ​ the​ ​ previous​ ​ head!
*/