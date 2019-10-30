#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

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

struct song_node * findnode (struct song_node * node, char title [] , char writer[]) {
  struct song_node * start = node;
  while (start != NULL) {
    if (strcmp (start -> name, title) == 0 && strcmp (start -> artist, writer) == 0) {
      return start;
    }
    start = start -> next;
  }
  return NULL;
}

struct song_node * findnodeArtist (struct song_node * node, char title [] , char writer[]) {
  struct song_node * start = node;
  while (start != NULL) {
    if (strcmp (start -> artist, writer)) {
      return start;
    }
    start = start -> next;
  }
  return NULL;
}

void insert_alpha (struct song_node *linkedlist, char newName[], char newArtist[]) {
  struct song_node *start = linkedlist;
  char artistandname [] = newName + newArtist;
  while (strcmp ( (start -> artist + start -> name),artistandname) < 0) {//if start is first before what you want to insert
    start = start -> next; //keep going through list until you find the place you want to insert
  }
  struct song_node * was = start -> next; //what is going to be after this song
  start -> next = linkedlist; //inserting song where it should be
  linkedlist -> next = was; //linking song to the next one
}
