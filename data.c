#include "data.h"

struct data* createData(int v)
{
  struct data *dta = malloc(sizeof(struct data));
  dta->val = v;
  return dta;
}

int getValue(struct data *dta)
{
  return dta->val;
}

void printData(struct data *dta)
{
  printf("%d\n",dta->val);
}


int compareData(struct data *lhs,struct data *rhs)
{
  return (lhs->val == rhs->val);

}
