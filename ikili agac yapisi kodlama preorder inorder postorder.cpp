#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node * rootnodecreate(int veri){
	struct node * root=(struct node *)malloc(sizeof(struct node));
	root->data=veri;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct node * push(struct node * root,int veri){
	
	if(root==NULL){
		root=rootnodecreate(veri);
	}
	else{
		if(veri<root->data){
			root->left=push(root->left,veri);    //elemanekle (push()) ve recursive fonksiyon i�levi
		}
		else{
			root->right=push(root->right,veri);
		}
		return root;
	}
}

void preorder(struct node * root){    // k�k (root) ba�ta
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);     //recursive olarak �a��r�ld�
		preorder(root->right);
	}
}

void inorder(struct node * root){    //k�k ortada
	if(root!=NULL){
		inorder(root->left);   //recursive olarak �a��r�ld�
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(struct node * root){    //k�k sonda
	if(root!=NULL){
		postorder(root->left);   //recursive olarak �a��r�ld�
		postorder(root->right);
		printf("%d ",root->data);
	}
}


int main(){
	struct node * eleman=NULL;
	int sayi,i=0;
	while(i<7){
		printf("sayi girin: ");
		scanf("%d",&sayi);
		eleman=push(eleman,sayi);
		i++;
	}
	printf("\npreOrder :");
	preorder(eleman);
	
	printf("\ninOrder :");
	inorder(eleman);
	
	printf("\npostOrder :");
	postorder(eleman);

	
	
	
}
