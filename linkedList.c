#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <string.h>

void print_list(struct song_node *linkedList){
  struct song_node *start = linkedList;
  //printf("%p", linkedList);
  while (start != NULL){
    printf("%s : %s | ", start->artist, start->name);
    start = start->next;
  }
}

void print_node(struct song_node *linkedList){
  if (linkedList != NULL){
    printf("%s : %s | ", linkedList->artist, linkedList->name);
  }
}



struct song_node * insert_front(struct song_node *linkedList, char newName[], char newArtist[]){
  struct song_node *input = malloc(sizeof(struct song_node));
  strcpy(input->name, newName);
  strcpy(input->artist, newArtist);
  input->next = linkedList;
  return input;
}


struct song_node * insert_alpha(struct song_node *linkedList, char newName[], char newArtist[]){
  struct song_node *input = malloc(sizeof(struct song_node));
  strcpy(input->artist, newArtist);
  strcpy(input->name, newName);
  int found = 0;
  char artistAndNameInput[100];
  artistAndNameInput[0] = '\0';
  strcat(artistAndNameInput,newArtist);
  strcat(artistAndNameInput,newName);
  struct song_node *start = linkedList;
  struct song_node *before = NULL;
  if (start == NULL){
    input->next = start;
    return input;
  }
  while (start != NULL & found == 0){
    char artistAndName[100];
    artistAndName[0] = '\0';
    strcat(artistAndName, start->artist);
    strcat(artistAndName, start->name);
    if (strcmp(artistAndName,artistAndNameInput) > 0){
      if (before != NULL){
        before->next = input;
      }
      input->next = start;
      found = 1;
      if (before != NULL){
        return linkedList;
      }
      return input;
    }
    before = start;
    start = start->next;
  }
    before->next = input;
    input->next = NULL;

  return linkedList;
}

struct song_node * findnode (struct song_node * node, char title [] , char writer[]) {
  struct song_node * start = malloc(sizeof(struct song_node));
  start = node;
  while (start != NULL) {
    if (strcmp (start -> name, title) == 0 & strcmp (start -> artist, writer) == 0) {
      return start;
    }
    start = start -> next;
  }
  return NULL;
}

struct song_node * findnodeArtist (struct song_node * node, char writer[]) {
  struct song_node * start = node;
  while (start != NULL) {
    if (strcmp (start -> artist, writer) == 0) {
      return start;
    }
    start = start -> next;
  }
  return NULL;
}

struct song_node * randomElement (struct song_node * node){
  struct song_node * start = node;
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
  if (target != NULL && findnode (list, target -> name, target -> artist) != NULL) {
    struct song_node * before = list;
    struct song_node * current = list;
    while (strcmp(current->artist,target->artist) != 0 & strcmp(current->name,target->name) != 0){
      before = current;
      current = current->next;
    }
    before->next = current->next;
    free(current);
  }
}


struct song_node * deleteSpecific2(struct song_node * list, char name[], char artist[]){
  struct song_node * before = NULL;
  struct song_node * current = list;
  while (current != NULL){
  if (strcmp(current->artist,artist) == 0 & strcmp(current->name,name) == 0){
    if (current == list){
      list = current->next;
    }
    else{
      before->next = current->next;
    }
    free(current);
    return list;
  }
  before = current;
  current = current->next;
}
return list;
}


struct song_node * free_list (struct song_node * list) {
  struct song_node *start = list;
  struct song_node *temp = list;
  while (start != NULL) {
    start = start -> next;
    //printf ("freeing node: "); print_node (temp); printf ("\n");
    free (temp);
    temp = start;
  }
  return start;
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
