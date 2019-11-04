//#include "linkedList.c"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add_node (struct song_node * l [], struct song_node * adding) {
  char a = adding -> artist;
  insert_alpha (l[a - 'a'], adding);
}

struct song_node * search_song (struct song_node * l[], char name [], char writer []) {
  int i = 0;
  while(i < 27) {
    struct song_node * now = l[i];
    if (findnode(now, name, writer)) {
      return findnode (now, name, writer);
    }
    i ++;
  }
  return NULL;
}

struct song_node * search_artist (struct song_node *l[], char writer []) {
  int i = 0;
  while (i < 27) {
    struct song_node * now = l[i];
    if (findnodeArtist (now, writer)) {
      return findnodeArtist (now, writer);
    }
    i ++;
  }
}

void print_letter (struct song_node *l[], char c) {
  int i,j;
  printf ("All entries starting with %c", c);
  for (i = 0; i < 27; i ++) {
    struct song_node * now = l[i];
    while (now != NULL) {
      if ( (now -> name)[0] == c) {
        printf ("%s", now -> name);
      }
      now = now -> next;
    }
  }
}

void print_artist (struct song_node *l[], char writer[]){
  int i,j;
  int exist = 0;
  for (i = 0; i < 27 & exist == 0; i++){
    if (findnodeArtist(l[i],writer) != NULL){
      exist = 1; //it exists and stops for loop
      printf("Artist found! ");
    }
  }
  if (exist == 0){
    printf("Artist not found! ");
  }
  for (j = 0; j < 27 & exist == 1; j++){
    struct song_node * currentPlaylist = l[j];
    struct song_node * start = &currentPlaylist[0];
    while(start != NULL){
      if (strcmp(start->artist,writer) == 0){//matching artist found
        printf("%s : %s | ", start->artist, start->name);
      }
      start = start->next;
    }
  }
}

void printlibrary (struct song_node *l[]){
  int i;
  for (i = 0; i <27; i++){
    struct song_node * currentPlayList = l[i]; //first node of linkedList
    struct song_node * start = &currentPlayList[0];
    //char firstArtist[100] = "\0";
    //strcat(firstArtist,start->artist);
    //char firstLetter[100] = "\0";
    //strcat(firstLetter,firstArtist);
    //printf("%s list\n", firstLetter);
    while(start != NULL){
      printf("%s : %s | ", start->artist, start->name);
      start=start->next;
    }
    printf("\n");
  }
}

void shuffle (struct song_node *l[]){
  int rand1 = random () % 27;
  int rand2 = random () % 27;
  int rand3 = random () % 27;
  struct song_node *currentPlaylist;
  currentPlaylist = l[rand1];
  print_node(randomElement(currentPlaylist));
  printf("\n");
  currentPlaylist = l[rand2];
  print_node(randomElement(currentPlaylist));
  printf("\n");
  currentPlaylist = l[rand3];
  print_node(randomElement(currentPlaylist));
  printf("\n");
}

void delete (struct song_node *l[], struct song_node *target){
  int i;
  int removed = 0;
  for (i = 0; i < 27 & removed == 0; i++){
    if (findnode(l[i],target->name,target->artist) != NULL){
      deleteSpecific(l[i],target);
      removed = 1;
    }
  }
}

void clear (struct song_node *l[]) {
  int i;
  for (i = 0; i < 27; i ++) {
    struct song_node * now = l[i];
    while (now != NULL) {
      now = NULL;
      now = now -> next;
    }
  }
}
