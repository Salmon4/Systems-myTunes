#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main () {
  printf ("LINKED LIST TESTS \n ========================================================\n");
  printf ("Testing print_list:\n");
  struct song_node * test;
  print_list (test);
  printf("\nAdding to list: \n");
  test = insert_front(test, "moo", "cow");
  print_list(test);
  printf("\n");
  test = insert_front(test, "woof", "dog");
  print_list(test);
  return 0;
}
