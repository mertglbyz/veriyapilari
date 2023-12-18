#include <stdio.h>
#include <stdlib.h>
 struct node{
 struct node *right
 struct node *left
}
typedef struct node BTREE;

BTREE*createroot(int data){
BTREE *root = (BTREE *)malloc(sizeof(struct node));
    void preorder(BTREE *root)
    if(root!=NULL){
    	printf("%d",root->data);
    	preorder(root ->left);
    	preorder(root ->right);
	}
	
    	
