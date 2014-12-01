#ifndef DATA_H_
#define DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include "variables.h"

//mallocs space for a data structure and sets the variable val insided of the structure equal to v
struct data* createData(int v);

//takes in a pointer to a data structure and returns the variable val as an integer
int getValue(struct data *dta);

//takes in a pointer to a data structure and prints the variable val followed by a new line                                                      
void printData(struct data *dta);

//takes in 2 pointers to data structures and compares them to see if the variable val in each input is equal.  
//if the 2 values are equal retun 1.  If they are not equal the return 0.
int compareData(struct data *lhs,struct data *rhs);
#endif
