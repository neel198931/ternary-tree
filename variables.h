#ifndef VARIABLES_H_
#define VARIABLES_H_

struct data
{
  int val;
};




struct node
{
  struct node* next;
  struct data* dta;
};

struct linkedList
{
  int size;
  struct node *head;
};

struct leaf
{
  struct linkedList* ll;
  struct leaf* left;
  struct leaf* right;
  struct leaf* center;
  struct leaf* parent;
};

struct tree
{
  struct leaf* root;
};


#endif
