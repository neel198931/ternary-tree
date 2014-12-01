#include "linkedList.h"
#include "data.h"
#include "variables.h"

int main()
{
  //create the linkedList
  struct linkedList *ll = createLinkedList();
  //insert items into the linked list in assending order
  insertLinkedList(ll,createData(4));
  insertLinkedList(ll,createData(5));
  insertLinkedList(ll,createData(2));
  insertLinkedList(ll,createData(7));
  
  //prints the linkedlist from head to tail
  printLinkedList(ll);

  //gets the data element at the head and prints it out
  struct data *hd = getHead(ll);
  printData(hd);

  //get the data element at the tail and print it out
  struct data *tl = getTail(ll);
  printData(tl);


  //get the size of the linkedlist and print it out
  int llSize = linkedListSize(ll);
  printf("linklist size: %d\n",llSize);

  cleanLinkedList(ll);
  return 0;
}
