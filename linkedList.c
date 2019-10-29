#include <stdio.h>
#include <stdlib.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
}

void print_list(struct song_node *linkedList){
  struct song_node *start = linkedList;
  while (start != NULL){
    printf("%s : %s |", start->name, start->artist);
    start = start->next;
  }
}

struct song_node * insert_front(struct song_node *linkedList, char newName[], char newArtist[]){
  struct song_node *input = malloc(sizeof(struct song_node));
  input->name = newName;
  input->artist = newArtist;
  return input;
}

struct song_node * insert_alpha(struct song_node *linkedList, char newName[], char newArtist[]){
  struct song_node *input = malloc(sizeof(struct song_node));
  input->artist = newArtist;
  input->name = newName;
  struct song_node *start = linkedList;
  while (start != NULL & found == 0){
    char artistAndname[] = start->artist + start->name;
    char artistAndnameInput[] = input->artist + input->name;
    if (artistAndname )
  }
}
