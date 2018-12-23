#include "my_malloc.h"
#include <stdio.h>

int main() {
  void *allocated[10];

  printf("Available memory before: %zd.\n", available_memory());
  for (int i = 0; i < 10; i++) {
    allocated[i] = my_malloc(100);
  }
  print_free_list();
  printf("Available memory after: %zd.\n", available_memory());

  printf("Available memory before: %zd.\n", available_memory());
  for (int i = 0; i < 10; i++) {
    my_free(allocated[i]);
  }
  print_free_list();
  printf("Available memory after: %zd.\n", available_memory());

  reset_heap();

  printf("Available memory before: %zd.\n", available_memory());
  for (int i = 0; i < 10; i++) {
    allocated[i] = my_malloc(100);
  }
  print_free_list();
  printf("Available memory after: %zd.\n", available_memory());

  printf("Available memory before: %zd.\n", available_memory());
  for (int i = 9; i >= 0; i--) {
    my_free(allocated[i]);
  }
  print_free_list();
  printf("Available memory after: %zd.\n", available_memory());

  return 0;
}
