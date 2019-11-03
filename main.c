#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main () {
  printf ("LINKED LIST TESTS \n========================================================\n");
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
  printf("This is the list:");
  print_list(test);
  printf("\n");
  printf("Testing find node: \n");
  printf("Looking for woof by dog\n");
  print_node(findnode(test,"woof","dog"));
  printf("\n");
  printf("Looking for meow by cat\n");
  print_node(findnode(test,"meow","cat"));
  printf("\n");
  printf("Looking for woof by bear\n");
  print_node(findnode(test,"woof","bear"));
  printf("\n");
  printf("Looking for oof by dog\n");
  print_node(findnode(test,"oof","dog"));
  printf("\n");
  printf("Looking for oof by bear\n");
  print_node(findnode(test,"oof","bear"));
  printf("\n");

  printf("========================================================\n");
  printf("Testing find artist: \n");
  printf("Looking for [dog]: %p\n", findnodeArtist (test,"dog"));
  printf("Looking for [bear]: %p\n", findnodeArtist (test,"bear"));
  printf("Looking for [fox]: %p\n", findnodeArtist (test,"fox"));

  printf("========================================================\n");
  printf ("Testing random\n");
  print_node (randomElement (test)); printf ("\n");
  print_node (randomElement (test)); printf ("\n");
  print_node (randomElement (test)); printf ("\n");
  print_node (randomElement (test)); printf ("\n");
  print_node (randomElement (test)); printf ("\n");
  print_node (randomElement (test)); printf ("\n");

  printf("========================================================\n");
  printf ("This is the list: \n");
  print_list (test); printf ("\n\n");
  printf ("Testing remove:\n");
  printf ("Removing [duck : quak]\n\t");
  deleteSpecific (test, findnodeArtist (test, "duck"));
  print_list (test);
  printf ("\nRemoving [dog : woof]\n\t");
  deleteSpecific (test, findnodeArtist (test, "dog"));
  print_list (test);
  printf ("\nRemoving [cow : moo]\n\t");
  deleteSpecific (test, findnodeArtist (test, "cow"));
  print_list (test);
  printf ("\nRemoving [bird : chirp]\n\t");
  deleteSpecific (test, findnodeArtist (test, "bird"));
  print_list (test);



  return 0;
}
