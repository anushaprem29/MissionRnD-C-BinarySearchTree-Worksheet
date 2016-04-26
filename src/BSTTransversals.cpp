/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorderT(struct node *r, int *arr, int *pos)
{
	if (r != NULL)
	{
		inorderT(r->left, arr, pos);
		arr[(*pos)++] = r->data;
		inorderT(r->right, arr, pos);
	}
	else return;
}

void inorder(struct node *root, int *arr){
	if (arr == NULL || root == NULL)	return;
	int iter = 0;
	inorderT(root, arr, &iter);
}
void preorderT(struct node *r, int *arr, int *pos)
{
	if (r != NULL)
	{
		arr[*pos] = r->data;
		(*pos)++;
		preorderT(r->left, arr, pos);
		preorderT(r->right, arr, pos);
	}
	else return;
}

void preorder(struct node *root, int *arr){

	if (arr == NULL || root == NULL)	return;
	int iter = 0;
	preorderT(root, arr, &iter);
}
void postorderT(struct node *r, int *arr, int *pos)
{
	if (r != NULL)
	{
		postorderT(r->left, arr, pos);
		postorderT(r->right, arr, pos);
		arr[*pos] = r->data;
		(*pos)++;
	}

	else return;
}

void postorder(struct node *root, int *arr){
	if (arr == NULL || root == NULL)	return;
	int iter = 0;
	postorderT(root, arr, &iter);
}

