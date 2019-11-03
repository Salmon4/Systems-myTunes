#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main () {
  printf ("LINKED LIST TESTS \n ========================================================\n");
  printf ("Testing print_list:\n");
  struct song_node * test;
  print_list (test);
  printf("\nAdding to list: \n");
  printf("Inserting moo by cow\n");
  test = insert_front(test, "moo", "cow");
  print_list(test);
  printf("\n");
  printf("Inserting woof by dog\n");
  test = insert_front(test, "woof", "dog");
  print_list(test);
  printf("\n");
  printf("Inserting quack by duck\n");
  test = insert_front(test, "quack", "duck");
  print_list(test);
  printf("\n");
  printf("Inserting meow by cat\n");
  test = insert_front(test, "meow", "cat");
  print_list(test);
  printf("\n");
  printf("Inserting ???? by fox\n");
  test = insert_front(test, "????", "fox");
  print_list(test);
  printf("\n");

  printf("========================================================\n");

  printf("Testing find node: \n");

  return 0;
}
