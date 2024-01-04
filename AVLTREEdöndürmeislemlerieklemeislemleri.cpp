#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
};

typedef struct node AVLTree;

int max(int x, int y){
	
	if(x>=y){
		return x;
	}
	else{
		return y;
	}
	//return x >= y ? x : y; //bunu öðren lazým olabilir ayný iþleve geliyor
}

int height(AVLTree *root){
    if(root == NULL)
        return -1;
    else
    {
        int Lheight, Rheight;
        Lheight = height(root->left);
        Rheight = height(root->right);

        if(Rheight > Lheight)
            return Rheight + 1;
        else 
            return Lheight + 1;
    }
}

AVLTree *RightRotate(AVLTree *z){
    AVLTree *temp = z->left;
    z->left = temp->right;
    temp->right = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

AVLTree *leftRotate(AVLTree *z){
    AVLTree *temp = z->right;
    z->right = temp->left;
    temp->left = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

AVLTree *leftRightRotate(AVLTree *z){
    z->left = leftRotate(z->left);
    return RightRotate(z);
}

AVLTree *rightLeftRotate(AVLTree *z){
    z->right = RightRotate(z->right);
    return leftRotate(z);
}

AVLTree *newNode(int data){
    AVLTree *p = (AVLTree *)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    p->height = 0;
    return p; 
}

AVLTree *insertToAVL(int x ,AVLTree *tree)
{
    if (tree != NULL)
    {
        if (x < tree->data)
            tree->left = insertToAVL(x, tree->left);
        else if(x > tree->data)
            tree->right = insertToAVL(x, tree->right);
        else
            return tree;

        tree->height = max(height(tree->left), height(tree->right)) + 1;
        if((height(tree->left) - height(tree->right)) > 1 && x < tree->left->data)
            return RightRotate(tree);

        if((height(tree->left) - height(tree->right)) > 1 && x > tree->left->data)
            return leftRightRotate(tree);

        if((height(tree->left) - height(tree->right)) < -1 && x > tree->right->data)
            return leftRotate(tree);

        if((height(tree->left) - height(tree->right)) < -1 && x < tree->right->data)
            return rightLeftRotate(tree);
    }   
    else
        tree = newNode(x);

    return tree;
}

void printTree(AVLTree *tree){
    if (tree != NULL)
    {
        printTree(tree->left);
        printf("%d\n",tree->data);
        printTree(tree->right);
    }
}


int main(){

    AVLTree *tree = NULL;

    int x;

    printf("Eklenecek sayiyi giriniz. (-1 programdan cikar.)");
    scanf("%d", &x);

    while (x != -1)
    {
        tree = insertToAVL(x, tree);
        scanf("%d", &x);
    }

    printTree(tree);
    printf("%d",tree->height);



    return 0;
}
