#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include "variables.h"
#include "data.h"


//mallocs space for a node structure and initialized the variables
//all node pointers are set to NULL while the data pointer is set equal to dt 
struct node* createNode(struct data *dt);

//mallocs space for a linkedList structure and sets head pointer to NULL and size to 0
struct linkedList* createLinkedList();

//inserts a new data struct into the linked list in increasing order
void insertLinkedList(struct linkedList* ll,struct data *dta);

//returns the data pointer that is located at the head of the linkedList
struct data* getHead(struct linkedList* ll);

//retures the data pointer that is located at the end of the linkedlist
struct data* getTail(struct linkedList* ll);

//returns the size variable that is located in the linkedList
int linkedListSize(struct linkedList* ll);

//prints the items in the linked list
//items will be printed out from smallest to largest
void printLinkedList(struct linkedList *ll);

//cleans all nodes in the linkedList as well as the linkedList
//also frees all data structs
void cleanLinkedList(struct linkedList *ll);
#endif
