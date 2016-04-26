/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

5
/ \
2   3
\
30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

9
/ \
4   1
/     \
20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorderT2(struct node *r, struct node* *arr, int *pos){
	if (r != NULL){
		inorderT2(r->left, arr, pos);
		arr[(*pos)++] = r;
		inorderT2(r->right, arr, pos);
	}
	else return;
}
void fix_bst(struct node *root){
	if (root == NULL)	return;
	int top = 0, iter, save;
	struct node **arr = (struct node **)malloc(sizeof(struct node*) * 100), *temp1 = (struct node *)malloc(sizeof(struct node)),
		*temp2 = (struct node *)malloc(sizeof(struct node));
	inorderT2(root, arr, &top);
	for (iter = 0; iter < top - 1; iter++){
		if (arr[iter]->data > arr[iter + 1]->data){
			temp1 = arr[iter];
			save = iter;
			break;
		}
	}
	if (iter == top - 1) return;
	for (iter++; iter < top - 1; iter++){
		if (arr[iter]->data > arr[iter + 1]->data){
			temp2 = arr[iter + 1];
			break;
		}
	}

	if (iter == top - 1) {
		temp2 = arr[save + 1];
	}
	iter = temp1->data;
	temp1->data = temp2->data;
	temp2->data = iter;
}
