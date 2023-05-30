//
//  linkedlist.h
//  
//
//  Created by Trey Tuscai on 3/18/22.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <stdlib.h>

//defines the Node structure
typedef struct Node
{
    //create data and next Node pointers
    void *data;
    struct Node *next;
}   Node;

//defines the LinkedList structure
typedef struct LinkedList
{
    //create head node pointer and store size of list
    Node *head;
    int size;
}   LinkedList;

//creates a LinkedList
LinkedList *ll_create();

//pushes a new value onto the list
void ll_push(LinkedList *l, void *data);

//pops a value off the list
void *ll_pop(LinkedList *l);

//adds a a new value to the end of the list
void ll_append(LinkedList *l, void *data);

//removes a value from the list that matches the target
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

//returns the size of the list
int ll_size(LinkedList *l);

//frees up all the memory in he list and clears it
void ll_clear(LinkedList *l, void (*freefunc)(void *));

//free function
void free(void *i);

//prints the list
void ll_map(LinkedList *l, void (*mapfunc)(void *));


#endif /* linkedlist_h */
