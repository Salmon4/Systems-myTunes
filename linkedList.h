struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

extern void print_list(struct song_node *linkedList);

extern struct song_node * insert_front(struct song_node *linkedList, char newName[], char newArtist[]);

extern struct song_node * insert_alpha(struct song_node *linkedList, char newName[], char newArtist[]);
//void insert_alpha (struct song_node *linkedlist, char newName[], char newArtist[]);

extern struct song_node * findnode (struct song_node * node, char title [] , char writer[]);

extern struct song_node * findnodeArtist (struct song_node * node, char writer[]);

extern struct song_node * randomElement (struct song_node * node);
extern void deleteSpecific (struct song_node * list, struct song_node *target);

extern struct song_node * free_list (struct song_node * list);
