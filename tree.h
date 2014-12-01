#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include "variables.h"
#include "data.h"
#include "linkedList.h"

//malloc space for a leaf and initialize the variables in the leaf structure
struct leaf* createLeaf();

//malloc space for a tree structure and initalize the variable root
struct tree* createTree();


//insert an item into the tree.  The function insertTree is called from main
void insertTree(struct tree *tr,struct data *dta);
void insertTree_r(struct leaf *lf,struct data *dta);


//prints out the items inserted into the tree.  The function printTree is called from main
void printTree(struct tree *tr);
void printTree_r(struct leaf *lf);

int getHeight(struct tree *tr);
int getHeight_r(struct leaf *lf);
int maxOfThree(int a, int b,int c);


int getMax(struct tree *tr);
int getMax_r(struct leaf *lf);

int getMin(struct tree *tr);
int getMin_r(struct leaf *lf);

int searchTree(struct tree *tr,struct data *dta);
int searchTree_r(struct leaf *lf,struct data *dta);
int searchLinkedList(struct linkedList *ll, struct data *dta);

int isFull(struct tree *tr);
int isFull_r(struct leaf *lf);


int isComplete(struct tree *tr);
int isComplete_r(struct leaf *lf);

void reverseTree(struct tree *tr);
void reverseTree_r(struct leaf *lf);

struct tree* copyTree(struct tree *tr);
void copyTree_r(struct leaf *lf, struct tree *trCopy);

int compareTree(struct tree *tr1, struct tree *tr2);
int compareTree_r(struct leaf *lf1, struct leaf *lf2);

int compareLinkedList(struct linkedList *list1,struct linkedList *list2);

//frees all memory in the tree.  the function cleanTree is called from main
void cleanTree(struct tree *tr);
void cleanTree_r(struct leaf *lf);
#endif
