#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}node;

int leftToComplete(node * T){
	node * curr = T, * curr_left = T, * curr_right = T;
	int h = -1;
	while (curr != NULL){
		curr=curr->left;
		h++;
	}
	curr = T;

	int hc = 0, h1, h2, n = 2, m;
	for (int i = 2; i<h; i++) n*=2;
	m = n;

	while (curr != NULL){
		h1 = h2 = hc;
		curr_left = curr->left;
		curr_right = curr->right;

		while (curr_left != NULL){
			curr_left = curr_left->right;
			h1++;
		}
		while(curr_right != NULL){
			curr_right = curr_right->left;
			h2++;
		}

		if (h1 != h2)
			return n;

		if (h1 == h){
			curr = curr->right;
			n-=m/2;
		}
		else{
			curr = curr->left;
			n+=m/2;
		}
		m/=2;
		hc++;
	}
	return 0;
}

int main(){
	node L1, L2, L3, L4, L5, L6, L7, L8, L9, L10;

	L1.left = &L2;
	L1.right = &L3;

	L2.left = &L4;
	L2.right = &L5;

	L3.left = &L6;
	L3.right = &L7;

	L4.left = &L8;
	L4.right = &L9;

	L5.left = &L10;
	L5.right = NULL;

	L6.left = NULL;
	L6.right = NULL;

	L7.left = NULL;
	L7.right = NULL;

	L8.left = NULL;
	L8.right = NULL;

	L9.left = NULL;
	L9.right = NULL;

	L10.left = NULL;
	L10.right = NULL;

	printf("Complete tree is missing %d node from being full\n", leftToComplete(&L1));
	return 0;
}
