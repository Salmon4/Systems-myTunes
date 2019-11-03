#include "linkedList.c"
#include "library.h"

int size (struct song_node *l [] start ) {
  int ans = 0;
  while (start [ans] != NULL) {
    ans ++;
  }
  return ans;
}

void add_node (struct song_node * l [], struct song_node * adding) {
  l[size (l) + 1] = adding;
}

struct song_node * search_song (struct song_node * l[], char name [], char writer []) {
  int i = 0;
  while(i < size (l)) {
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
  while (i < size (l)) {
    struct song_node * now = l[i];
    if (findnodeArtist (now, writer)) {
      return findnodeArtist (now, writer);
    }
    i ++;
  }
}

void print_letter (struct song_node *l[], char c) {
  int i,j;
  prinft ("All entries starting with %c", c);
  for (i = 0; i < size (l); i ++) {
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
  for (i = 0; i < size(l) & exist == 0; i++){
    if (findnodeArtist(l[i],writer) != NULL){
      exist = 1; //it exists and stops for loop
      printf("Artist found! ");
    }
  }
  if (exist == 0){
    printf("Artist not found! ");
  }

  for (j = 0; j < size(l) & exist == 1, j++){
    struct song_node * start = l[j];
    while(start != NULL){
      if (strcmp(start[j]->artist,writer) == 0){//matching artist found
        printf("%s : %s | ", start[j]->artist, start[j]->name);
      }
      start = start->next;
    }
  }
}
void printlibrary (struct song_node *l[]);
void shuffle (struct song_node *l[]);
void delete (struct song_node *l[], struct song_node *target);
void clear (struct song_node *l[]);
