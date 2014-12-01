#include "linkedList.h"


struct node* createNode(struct data *dt)
{
  struct node *n = malloc(sizeof(struct node));
  n->next = NULL;
  n->dta = dt;
  return n;

}


struct linkedList* createLinkedList()
{
  struct linkedList* ll = malloc(sizeof(struct linkedList));
  ll->head = NULL;
  ll->size = 0;
  return ll;
}


void insertLinkedList(struct linkedList *ll,struct data *dta)
{
  ll->size+=1;
  struct node *n = createNode(dta);
  if(ll->head == NULL)
    ll->head = n;
  else
    {
      struct node *tmp = ll->head;
      struct node *prev = ll->head;
      while(tmp != NULL && getValue(tmp->dta) <= getValue(dta))
	{
	  prev = tmp;
	  tmp = tmp->next;
	}
      if(tmp == NULL)
	{
	  prev->next = n;
	}
      else if(tmp == ll->head)
	{
	  n->next = ll->head;
	  ll->head = n;
	}
      else
	{
	  prev->next = n;
	  n->next = tmp;
	}
    }

}

struct data* getHead(struct linkedList* ll)
{
  return ll->head->dta;
}

struct data* getTail(struct linkedList* ll)
{
  struct node* tmp = ll->head;
  while(tmp->next != NULL)
    {
      tmp=tmp->next;
    }
  return tmp->dta;
}

int linkedListSize(struct linkedList* ll)
{
  return ll->size;
}

void printLinkedList(struct linkedList *ll)
{
  struct node* tmp = ll->head;
  while(tmp != NULL)
    {
      printData(tmp->dta);
      tmp=tmp->next;
    }
  printf("\n");
}

void cleanLinkedList(struct linkedList *ll)
{
  struct node *tmp = ll->head;
  while(tmp != NULL)
    {
      struct node *nxt = tmp->next;
      free(tmp->dta);
      free(tmp);
      tmp = nxt;
    }
  free(ll);
  
}
