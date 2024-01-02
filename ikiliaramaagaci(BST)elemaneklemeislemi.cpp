#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node * newNodeCreate(int data){
	
	struct node * newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;  
}

void inorder(struct node * node){
	
	if(node!=NULL){
		inorder(node->left);       //sol
		printf("%d ",node->data);  // root
		inorder(node->right);     //sað
	}
}

void preorder(struct node * node){
	if(node!=NULL){
		printf("%d ",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(struct node * node){
	if(node!=NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->data);
	}
}

struct node * insert(struct node * root, int insertdata){
	if(root==NULL){
		return newNodeCreate(insertdata);
	}
	if(insertdata<root->data){
		root->left=insert(root->left,insertdata);
	}
	if(insertdata>root->data){
		root->right=insert(root->right,insertdata);  
	}
	return root;
}



int main(){
	struct node * root =NULL;
	root=insert(root, 20);
	insert(root, 30);
	insert(root, 2);
	insert(root, 43);
	insert(root, 15);
	insert(root, 17);
	insert(root, 6);
	insert(root, 8);
	
	preorder(root);
	inorder(root);
	postorder(root);
	
	
	
}
