//
//  linkedlist.c
//  
//
//  Created by Trey Tuscai on 3/13/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//creates a LinkedList
LinkedList *ll_create()
{
    //create new list and allocate memory
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    //head node is equal to null
    linkedList->head = NULL;
    //size of list is 0
    linkedList->size = 0;
    return linkedList;
}

//pushes a new value onto the list
void ll_push(LinkedList *l, void *data)
{
    //create a new Node
    Node *newNode = (Node*)malloc(sizeof(Node));
    //allocate data size
    newNode->data = malloc(sizeof(data));
    //set next to head
    newNode->next = l->head;
    //assign new Node's value
    newNode->data = data;
    //head equal to new Node
    l->head = newNode;
    //increase size
    l->size += 1;
    //printf("Next: %p\n", newNode->next->data);
}

//pops a value off the list
void *ll_pop(LinkedList *l)
{
    //when list is not empty
    if(l->head != NULL)
    {
        //save data from head node
        void *data = l->head->data;
        //head points now to the next Node
        l->head = l->head->next;
        //printf("Popped: %p\n", data);
        //return the popped data
        //decrease size by 1
        l->size -= 1;
        return data;
    }
    else
    {
        //when list is empty return nothing
        //printf("List is empty. Cannot pop.");
        return NULL;
    }
}

//adds a a new value to the end of the list
void ll_append(LinkedList *l, void *data)
{
    //create new Node and allocate memory
    Node *newNode = (Node*)malloc(sizeof(Node));
    //allocate data size
    newNode->data = malloc(sizeof(data));
    //set endnode equal to head
    Node *endNode = l->head;
    //assign new Node's data
    newNode->data = data;
    newNode->next = NULL;
    
    //if list is empty, Node is equal to head
    if(l->head == NULL)
    {
        newNode->next = l->head;
        l->head = newNode;
    }
    else
    {
        //iterate through the list to reach the last node
        while(endNode->next != NULL)
        {
            //printf("Endnode's next Node: %d\n", *(int *)endNode->data);
            endNode = endNode->next;
            //printf("Endnode's next Node: %d\n", *(int *)endNode->data);
        }
        //set the end node equal to new Node
        endNode->next = newNode;
        //printf("Added to end: %d\n", *(int *)newNode->data);
        //printf("Added to end: %p\n", newNode->data);
    }
    //increase size by 1
    l->size += 1;
}

//removes a value from the list that matches the target
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *))
{
    if(l->head != NULL)
    {
        Node *currentNode = l->head;
        if(compfunc(l->head->data, target))
        {
            l->head = l->head->next;
            //decrease size by 1
            l->size -= 1;
            return currentNode->data;
        }
        else
        {
            Node *prevNode = NULL;
            while (currentNode != NULL && !compfunc(currentNode->data, target))
            {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            if(currentNode != NULL)
            {
                prevNode->next = currentNode->next;
                //decrease size by 1
                l->size -= 1;
                //printf("Removed: %d\n", *(int *)currentNode->data);
                return currentNode->data;
            }
        }
    }
    return NULL;
}

//returns the size of the list
int ll_size(LinkedList *l)
{
    //return list size
    return l->size;
}

//frees up all the memory in the list and clears it
void ll_clear(LinkedList *l, void (*freefunc)(void *))
{
    Node* current = l->head;
    Node* next;
     
    //frees each node in the list
    while (current != NULL)
       {
           next = current->next;
           free(current);
           current = next;
           l->size -= 1;
       }
       //head is now NULL so list is cleared
       l->head = NULL;
}

//maps the data and prints it
//uses mapfunc
void ll_map(LinkedList *l, void (*mapfunc)(void *))
{
    //prints each node in the list
    Node *tmp = l->head;
    while (tmp != NULL)
        {
            mapfunc(tmp->data);
            tmp = tmp->next;
        }
}

