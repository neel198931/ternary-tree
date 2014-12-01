#include "linkedList.h"
#include "data.h"
#include "tree.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
		return 0;

	struct tree *tr = createTree();
	int i=0;
	for(i=1; i<argc; i++) {
		insertTree(tr,createData(atoi(argv[i])));
	}

	printTree(tr);
	printf("Height of tree is %d\n\n",getHeight(tr));
	printf("Min Value is %d\n\n",getMin(tr));
	printf("Max Value is %d\n\n",getMax(tr));
	printf("Is Complete %d\n\n",isComplete(tr));
	printf("Is Full %d\n\n",isFull(tr));

//	struct data *key = createData(10);
//	printf("Search for 10 is %d\n\n",searchTree(tr,key));
//	free(key);
//	struct tree *tr2 = copyTree(tr);

//	printf("Compare tree %d\n\n",compareTree(tr,tr2));

//	printTree(tr2);

//      printf("Min Value is %d\n\n",getMin(tr2));
//        printf("Max Value is %d\n\n",getMax(tr2));

//	reverseTree(tr2);
//	printTree(tr2);

//        printf("Compare tree %d\n\n",compareTree(tr,tr2));
	cleanTree(tr);
//	cleanTree(tr2);
	return 0;
}
