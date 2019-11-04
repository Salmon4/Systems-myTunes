#include "linkedList.h"
void add_node (struct song_node * l [],  char name[], char artist[]);
struct song_node * search_song (struct song_node * l[], char name [], char writer []);
struct song_node * search_artist (struct song_node *l[], char writer []);
void print_letter (struct song_node *l[], char c);
void print_artist (struct song_node *l[], char writer[]);
void printlibrary (struct song_node *l[]);
void shuffle (struct song_node *l[]);
void delete (struct song_node *l[], char song[], char writer []);
void clear (struct song_node *l[]);
