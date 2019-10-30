#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

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

struct song_node * randomElement (struct song_node * node){
  struct song_node * start1 = node;
  int length = 0;
  while (start != NULL) {
    length ++;
    start = start -> next;
  }
  int rand = random () % length;
  struct song_node *start2 = node;
  while (rand >  0) {
    start2 = start2 -> next;
    rand --;
  }
  return start2;
}

void deleteSpecific (struct song_node * list, struct song_node *target) {
  struct song_node * start = list;
  struct song_node * current = list;
  if (start != NULL){
    return list;
  }
  if (strcomp(current->artist,target->artist) == 0 && strcomp(current->name,target->name) == 0){
    free(start);
    list = list->next;
  }
  while(strcomp(start->artist,target->artist) == 0 && strcomp(start->name,target->name) {
    current = start;
    start = start->next;
  }
  current->next = start->next;
  free(start);
}

void free_list (struct song_node * list) {
  struct song_node *start = list;
  struct song_node *temp = list;
  while (start != NULL) {
    start = start -> next;
    free (temp);
    temp = start;
  }
}

/*
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
*/
