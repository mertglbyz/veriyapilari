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

struct node * searchtree(struct node *root, int searchdata){
	if(root!=NULL){
		printf("\n kontrol edilen sayi: %d ",root->data);
	}
	if(root->data==searchdata){
		return root;
	}
	if(searchdata<root->data){
		return searchtree(root->left, searchdata);
	}
	else{
		return searchtree(root->right, searchdata);
	}
}

struct node * minNode(struct node * baslangic){  // eleman silme iþlemi için silinecek elemanýn sað çocuðundan itibaren en küçük deðeri bulma islemi
	struct node * mevcut=baslangic;
	while(mevcut!=NULL && mevcut->left!=NULL){
		mevcut=mevcut->left;
	}
	return mevcut;
}

struct node * deleteNode(struct node * root, int silinecek){
	if(root==NULL){
		return root;
	}
	if(silinecek<root->data){
		root->left=deleteNode(root->left,silinecek);
	}
	else if(silinecek>root->data){
		root->right=deleteNode(root->right,silinecek);
	}
	else{
		if(root->left==NULL){
			struct node * temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node * temp=root->left;
			free(root);
			return temp;
		}
		struct node * minRight = minNode(root->right); // sað
        root->data = minRight->data;
        root->right = deleteNode(root->right, minRight->data);
        
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
	insert(root, 40);
	insert(root, 41);
	insert(root, 45);

	
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	
	searchtree(root, 15);   //aranacak sayi yazilir
	root=deleteNode(root, 41);
	inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
	
	
}
