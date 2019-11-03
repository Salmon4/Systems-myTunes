struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *linkedList);

struct song_node * insert_front(struct song_node *linkedList, char newName[], char newArtist[]);

void insert_alpha(struct song_node *linkedList, char newName[], char newArtist[]);
//void insert_alpha (struct song_node *linkedlist, char newName[], char newArtist[]);

struct song_node * findnode (struct song_node * node, char title [] , char writer[]);

struct song_node * findnodeArtist (struct song_node * node, char writer[]);

struct song_node * randomElement (struct song_node * node);
void deleteSpecific (struct song_node * list, struct song_node *target);

struct song_node * free_list (struct song_node * list);
