#include <stdio.h>
#include <stdlib.h>
struct node{ 
	//struct yap�s� olu�turma
	int data;
	struct node*head;
};




int main(){
	struct node* bir;         //d���m (node) olu�turma
	bir= (struct node*)malloc(sizeof(struct node));      // bellekte yer ay�rma (yer tahsis etme)
	
	struct node* iki;
	iki= (struct node*)malloc(sizeof(struct node));
	
	struct node* uc;
	uc= (struct node*)malloc(sizeof(struct node));
	
	struct node* dort;
	dort= (struct node*)malloc(sizeof(struct node));
	
	bir -> data=11;          // veri(data) giri�i yap�ld�
	bir ->head= iki;         // bir sonraki d���m (node) g�sterildi
	
	iki -> data=22;
	iki ->head= uc;
	
	uc -> data=33;
	uc ->head= dort;
	
	dort -> data=44;
	dort ->head= NULL;
	
	printf("%d  -  %d  -  %d  - %d",bir ->data, iki->data,uc ->data,dort ->data );
	
	return 0;
}
