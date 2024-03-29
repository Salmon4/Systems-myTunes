#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main () {
  printf ("LINKED LIST TESTS \n========================================================\n");
  printf ("Testing print_list:\n");
  struct song_node * test;
  print_list (test);
  printf("\nAdding to list using insert_alpha: \n");
  struct song_node *test2;
  printf("Current list:\n");
  print_list(test2);
  printf("\nadding song1 by artist1 \n");
  test2 = insert_alpha(test2,"song1","artist1");
  print_list(test2);
  printf("\nadding song2 by artist1 \n");
  test2 = insert_alpha(test2,"song2","artist1");
  print_list(test2);
  printf("\n");
  printf("adding song0 by artist1 \n");
  test2 = insert_alpha(test2,"song0","artist1");
  print_list(test2);
  printf("\n");
  printf("adding song1 by artist2 \n");
  test2 = insert_alpha(test2,"song1","artist2");
  print_list(test2);
  printf("\n");
  printf("adding song2 by artist2 \n");
  test2 = insert_alpha(test2,"song2","artist2");
  print_list(test2);
  printf("\n");
  printf("adding song0 by artist2 \n");
  test2 = insert_alpha(test2,"song0","artist2");

  //test2 = insert_alpha(test2,"song3","artist2");
  printf("\n");
  print_list(test2);
    printf("\n========================================================\n");
  printf("\nAdding to new list using insert_front: \n");
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
  printf ("\nRemoving [quack : duck]\n\t");
  deleteSpecific (test, findnodeArtist (test, "quack"));
  print_list (test);
  printf ("This is the list: \n");
  print_list (test);  printf("\n\n");
  printf ("Testing free list\n");
  test = free_list (test);
  print_list (test);

  printf("=================LIBRARY TESTING========================\n");
  printf ("\nMUSIC LIBRARY TESTS\n");
  printf("========================================================\n");
  int i;
  struct song_node * lib[27];
  for (i = 0; i < 27; i++){
    lib[i] = NULL;
  }
  add_node(lib,"song0","steve");
  add_node(lib,"sounds","steve");
  add_node(lib,"pew","allen");
  add_node (lib, "song1", "oneartist");
  add_node (lib, "song2", "twoartist");
  add_node (lib, "song3", "threeartist");
  add_node (lib, "song4", "fourartist");
  add_node (lib, "song5", "fiveartist"); 
  printlibrary (lib);

  print_letter(lib,'s');
  struct song_node *dummy = NULL;
  printf("\n");
  dummy = search_song(lib,"pew","allen");
  if (dummy != NULL){
    printf("\nFound pew by allen: \n");
    print_node(dummy);
  }
  else{
    printf("not found");
  }
  printf ("\n");

  printf ("\nTesting shuffle: \n");
  printf("First Shuffle:\n");
  shuffle (lib);
  printf("Second Shuffle:\n");
  shuffle (lib);
  printf("Third Shuffle:\n");
  shuffle (lib);
  printf("Fourth Shuffle:\n");
  shuffle (lib);


  printf ("\n\nTesting print_artist: \n");
  print_artist (lib, "allen");
  print_artist (lib, "steve");
  print_artist (lib, "bob");


  printf ("\nTesting delete: \n");
  //delete (lib, "pew", "allen");
  printf ("List before deleting song0:\n");
  printlibrary (lib);
  delete (lib, "song0","steve");
  printf ("\nList after deleting song0:\n");
  printlibrary (lib);


  printf ("\nTesting clear: \n");
  clear (lib);
  printlibrary (lib);

  return 0;
}
