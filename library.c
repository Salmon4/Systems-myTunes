//#include "linkedList.c"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_index(char a[100]){
  int letter = a[0];
  if (letter >= 97 && letter <= 122){
    return letter % 97;
  }
  return 26;
}

void add_node (struct song_node * l[], char name[], char artist[]) {

  int an = find_index(artist);
  l[an] = insert_alpha(l[an], name, artist);
  //selected = insert_alpha (selected, name, artist);
  //print_list(selected);
  //printf("%d ", an);
  //printf("\n");
}

struct song_node * search_song (struct song_node * l[], char name [], char writer []) {
  /**
  int i = 0;
  while(i < 27) {
    struct song_node * now = l[i];
    if (findnode(now, name, writer)) {
      return findnode (now, name, writer);
    }
    i ++;
  }
  return NULL;
  **/
  int index = find_index(writer);
  return findnode(l[index],name,writer);
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
  printf ("\nAll entries starting with %c\n", c);
  int index;
  if (c >= 97 && c <= 122){
    index = c % 97;
  }
  else{
    index = 26;
  }
  //int index = find_index(c);
  print_list(l[index]);
  /**
  for (i = 0; i < 27; i ++) {
    struct song_node * now = l[i];
    while (now != NULL) {
      if ( (now -> name)[0] == c) {
        printf ("%s", now -> name);
      }
      now = now -> next;
    }
  }
  **/
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
  printf ("\n");
}

void printlibrary (struct song_node *l[]){
  int i;
  for (i = 0; i < 27; i++){
    if (l[i] != NULL){
      if (i != 26){
        printf("%c list\n", 97 + i);
      }
      else{
        printf("other list\n");
      }
      printf(" ");
      print_list(l[i]);
      printf("\n");
    }
  }
  printf("\n");
}

void shuffle (struct song_node *l[]){
  int times = 0;
  while (times < 26) {
    int r = rand () % 26;
    if (l[r] != NULL) {
      print_node (randomElement (l[r])); 
    }
    times ++;
  }
  /*
  int i;
  for (i = 0; i < 4; i++){
    int chosen = rand() % 26;
    if (l[chosen] != NULL){
      struct song_node * song = randomElement(l[chosen]);
      if (song != NULL){
      print_node(song);
      printf("  ");
      }
      else{
        i--;
      }
    }
  }
  printf("\n");
  */
  /*
  int i = 0;
  while (i < 27) {
    int r = random () % 26;
    print_node (randomElement, l[r]);
    i ++;
  }
  */
  /**
  int i ;
  for (i = 0; i < 4; i ++) {
    int r = random () % 27;
    if (l[r] != NULL) {
      struct song_node * now = l[r];
      while (now != NULL) {
        print_node (now);
        now = now -> next;
      }
    }
    else{
      i--;
    }
  }
  printf ("\n");
  **/
  /*
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
  */
}

void delete (struct song_node *l[], char song[], char writer []){
  int index = writer[0] - 'a';
  struct song_node * target;
  strcpy(target->name, song);
  strcpy(target->artist, writer);
  target -> next = NULL;
  deleteSpecific (l[index], target);
  /**
  struct song_node * found = search_song (l, song, writer);
  if (found != NULL) {
    deleteSpecific (l[find_index (found -> artist)], found);
  }
  **/
  /*
  struct song_node * target;
  strcpy(target->name, song);
  strcpy(target->artist, writer);
  int i;
  for (i = 0; i < 27; i ++) {
    struct song_node * now = l[i];
    if (findnode (now, target -> name, target -> artist)) {
      deleteSpecific (now, target);
    }
  }
  */
  /*
  int i;
  int removed = 0;
  for (i = 0; i < 27 & removed == 0; i++){
    if (findnode(l[i],song,writer) != NULL){
      struct song_node * target;
      strcpy(target->name, song);
      strcpy(target->artist, writer);
      deleteSpecific(l[i],target);
      removed = 1;
    }
  }
  */
}

void delete2 (struct song_node *l[], struct song_node * target){
  int index = find_index(target->artist);
  deleteSpecific(l[index],target);
  /**
  int i;
  int removed = 0;
  for (i = 0; i < 27 & removed == 0; i++){
    if (findnode(l[i],target-> name, target -> artist) != NULL){
      deleteSpecific(l[i], target);
      removed = 1;
    }
  }
  **/
}

void clear (struct song_node *l[]) {
  int i;
  for (i = 0; i < 27; i ++) {
    //struct song_node * now = l[i];
    l[i] = free_list(l[i]);
  }
}
