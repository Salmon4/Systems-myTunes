#include "linkedList.c"
#include "library.h"

int size (struct song_node *start [] ) {
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
  printf ("All entries starting with %c", c);
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
  for (j = 0; j < size(l) & exist == 1; j++){
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
  for (i = 0; i <size(l); i++){
    struct song_node * currentPlayList = l[i]; //first node of linkedList
    struct song_node * start = &currentPlayList[0];
    char firstArtist[100];
    strcat(firstArtist,start->artist);
    char firstLetter[100];
    strcat(firstLetter,firstArtist);
    printf("%s list\n", firstLetter);
    while(start != NULL){
      printf("%s : %s | ", start->artist, start->name);
      start=start->next;
    }
    printf("\n");
  }
}

void shuffle (struct song_node *l[]){
  int rand1 = random () % length;
  int rand2 = random () % length;
  int rand3 = random () % length;
  struct song_node *crurentPlaylist;
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
//void delete (struct song_node *l[], struct song_node *target);
//void clear (struct song_node *l[]);
