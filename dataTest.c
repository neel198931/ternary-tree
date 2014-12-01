#include "variables.h"
#include "data.h"

int main()
{

  //create 3 data structures
  struct data *dta1 = createData(3);
  struct data *dta2 = createData(3);
  struct data *dta3 = createData(7);


  //print out each of the data structures
  printData(dta1);
  printData(dta2);
  printData(dta3);

  //get the values of variable val in each of the data structures and print them out
  int val1 = getValue(dta1);
  int val2 = getValue(dta2);
  int val3 = getValue(dta3);

  printf("%d %d %d\n",val1,val2,val3);

  //compare the first and second data structures and print out the result
  int comp1 = compareData(dta1,dta2);
  printf("compare dta1 and dta2: %d\n",comp1);

  //compare the first and third data structures and print out the result
  int comp2 = compareData(dta1,dta3);
  printf("compare dta1 and dta3: %d\n",comp2);


  //free the memory for each of the created data sturctures
  free(dta1);
  free(dta2);
  free(dta3);


  return 0;
}
