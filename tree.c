#include "tree.h"
struct leaf* createLeaf() {
	struct leaf *lf = malloc(sizeof(struct leaf));
	lf->ll = createLinkedList();
	lf->parent = NULL;
	lf->left = NULL;
	lf->right = NULL;
	lf->center = NULL;
	return lf;

}

//malloc space for a tree structure and initalize the variable root
struct tree* createTree() {
	struct tree *tr = malloc(sizeof(struct tree));
	tr->root = NULL;
	return tr;
}

//insert an item into the tree.  The function insertTree is called from main
void insertTree(struct tree *tr,struct data *dta) {
	if(tr->root == NULL) {
		struct leaf *newLeaf = createLeaf();
		insertLinkedList(newLeaf->ll,dta);
		tr->root = newLeaf;
	} else {
		insertTree_r(tr->root,dta);
	}

}

void insertTree_r(struct leaf *lf,struct data *dta) {
	if(linkedListSize(lf->ll) < 3) {
		insertLinkedList(lf->ll,dta);
		return;
	}
	if(getValue(getHead(lf->ll)) > getValue(dta)) {
		//go to left
		if(lf->left == NULL) {
			struct leaf *newLeaf = createLeaf();
			insertLinkedList(newLeaf->ll,dta);
			lf->left = newLeaf;
			lf->left->parent = lf;
		} else {
			insertTree_r(lf->left,dta);
		}
	}else if(getValue(getTail(lf->ll)) < getValue(dta)) {
		//go to right
		if(lf->right == NULL) {
                        struct leaf *newLeaf = createLeaf();
                        insertLinkedList(newLeaf->ll,dta);
                        lf->right = newLeaf;
                        lf->right->parent = lf;
		} else {
			insertTree_r(lf->right,dta);
		}
	} else {
		//go to center
		if(lf->center == NULL) {
                        struct leaf *newLeaf = createLeaf();
                        insertLinkedList(newLeaf->ll,dta);
                        lf->center = newLeaf;
                        lf->center->parent = lf;
		} else {
			insertTree_r(lf->center,dta);
		}
	}
}


void printTree(struct tree *tr) {
	printTree_r(tr->root);
}

void printTree_r(struct leaf *lf) {
	if(lf == NULL) {
		return;
	}
	printLinkedList(lf->ll);
	printTree_r(lf->left);
	printTree_r(lf->center);
	printTree_r(lf->right);
}

int getHeight(struct tree *tr) {
	return getHeight_r(tr->root);
}

int getHeight_r(struct leaf *lf) {
	if(lf==NULL)
		return 0;
	return 1 + maxOfThree(getHeight_r(lf->left),getHeight_r(lf->right),getHeight_r(lf->center));
}

int maxOfThree(int a,int b,int c) {
        if(a>b && a>c) {
                return a;
        } else if(b>c) {
                return b;
        }
        return c;
}

int isFull(struct tree *tr) {
	return isFull_r(tr->root);
}

int isFull_r(struct leaf *lf) {
	if(lf==NULL)
		return 0;
	if(lf->left == NULL && lf->right == NULL && lf->center == NULL && linkedListSize(lf->ll) == 3)
		return 1;
	return (isFull_r(lf->left) && isFull_r(lf->right) && isFull_r(lf->center));
}

int isComplete(struct tree *tr) {
	if(tr->root == NULL)
		return 0;
	return isComplete_r(tr->root);
}

int isComplete_r(struct leaf *lf) {
	if(lf == NULL || lf->right == NULL || lf->left== NULL || lf->center == NULL)
		return 1;
	if(getHeight_r(lf->right) != getHeight_r(lf->left) || getHeight_r(lf->left) != getHeight_r(lf->center))
		return 0;
	return (isComplete_r(lf->left) && isComplete_r(lf->center) && isComplete_r(lf->right));
}

int getMax(struct tree *tr) {
	if(tr->root == NULL)
		return 0;
	return getMax_r(tr->root);
}

int getMax_r(struct leaf *lf) {
	if(lf->right == NULL)
		return getValue(getTail(lf->ll));
	return getMax_r(lf->right);
}

int getMin(struct tree *tr) {
	if(tr->root == NULL)
		return 0;
	return getMin_r(tr->root);
}

int getMin_r(struct leaf *lf) {
        if(lf->left == NULL)
                return getValue(getHead(lf->ll));
        return getMin_r(lf->left);
}

int searchTree(struct tree *tr,struct data *dta) {
	if(tr->root == NULL)
		return 0;
	return searchTree_r(tr->root,dta);
}

int searchTree_r(struct leaf *lf,struct data *dta) {
	if(lf==NULL)
		return 0;
	if(searchLinkedList(lf->ll,dta) == 1)
		return 1;
	return (searchTree_r(lf->left,dta) || searchTree_r(lf->center,dta) || searchTree_r(lf->right,dta));
}

int searchLinkedList(struct linkedList *ll, struct data *dta) {
	struct node *temp = ll->head;
	while(temp!=NULL) {
		if(compareData(temp->dta,dta))
			return 1;
		temp = temp->next;
	}
	return 0;
}

void reverseTree(struct tree *tr) {
	if(tr->root == NULL)
		return;
	reverseTree_r(tr->root);
}

void reverseTree_r(struct leaf *lf) {
	if(lf->left == NULL && lf->right == NULL)
		return;
	if(lf->left == NULL) {
		reverseTree_r(lf->right);
		lf->left = lf->right;
		lf->right = NULL;
		return;
	}
	if(lf->right == NULL) {
		reverseTree_r(lf->left);
		lf->right = lf->left;
		lf->right = NULL;
		return;
	}
	reverseTree_r(lf->left);
	reverseTree_r(lf->center);
	reverseTree_r(lf->right);
	struct leaf *temp = lf->left;
	lf->left = lf->right;
	lf->right = temp;
}

struct tree* copyTree(struct tree *tr) {
	struct tree *trCopy = createTree();
	copyTree_r(tr->root,trCopy);
	return trCopy;
}

void copyTree_r(struct leaf *lf, struct tree *trCopy) {
	if(lf == NULL)
		return;
	struct node *temp = (lf->ll->head);
	while(temp!=NULL) {
		insertTree(trCopy,createData(getValue(temp->dta)));
		temp = temp->next;
	}
	copyTree_r(lf->left,trCopy);
	copyTree_r(lf->center,trCopy);
	copyTree_r(lf->right,trCopy);
	return;
}

int compareTree(struct tree *tr1, struct tree *tr2) {
	return compareTree_r(tr1->root, tr2->root);
}

int compareTree_r(struct leaf *lf1, struct leaf *lf2) {
	if(lf1 == NULL && lf2 == NULL) {
		return 1;
	}else if(lf1 == NULL) {
		return 0;
	}else if(lf2 == NULL) {
		return 0;
	}
	if(compareLinkedList(lf1->ll,lf2->ll) == 0)
		return 0;
	return (compareTree_r(lf1->right,lf2->right) && compareTree_r(lf1->center,lf2->center) && compareTree_r(lf1->left,lf2->left));
}

int compareLinkedList(struct linkedList *list1,struct linkedList *list2) {
	struct node *node1 = list1->head;
	struct node *node2 = list2->head;
	while(node1 != NULL && node2 != NULL) {
		if(getValue(node1->dta) != getValue(node2->dta))
			return 0;
		node1 = node1->next;
		node2 = node2->next;
	}
	if(node1 != NULL || node1 !=NULL)
		return 0;
	return 1;
}


//frees all memory in the tree.  the function cleanTree is called from main
void cleanTree(struct tree *tr) {
	cleanTree_r(tr->root);
	free(tr);
}

void cleanTree_r(struct leaf *lf) {
	if(lf==NULL) {
		return;
	}
	cleanTree_r(lf->left);
	cleanTree_r(lf->center);
	cleanTree_r(lf->right);
	cleanLinkedList(lf->ll);
	free(lf);
}
