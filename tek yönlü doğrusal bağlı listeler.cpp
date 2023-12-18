#include <stdio.h>
#include <stdlib.h>
struct node{ 
	//struct yapısı oluşturma
	int data;
	struct node*head;
};




int main(){
	struct node* bir;         //düğüm (node) oluşturma
	bir= (struct node*)malloc(sizeof(struct node));      // bellekte yer ayırma (yer tahsis etme)
	
	struct node* iki;
	iki= (struct node*)malloc(sizeof(struct node));
	
	struct node* uc;
	uc= (struct node*)malloc(sizeof(struct node));
	
	struct node* dort;
	dort= (struct node*)malloc(sizeof(struct node));
	
	bir -> data=11;          // veri(data) girişi yapıldı
	bir ->head= iki;         // bir sonraki düğüm (node) gösterildi
	
	iki -> data=22;
	iki ->head= uc;
	
	uc -> data=33;
	uc ->head= dort;
	
	dort -> data=44;
	dort ->head= NULL;
	
	printf("%d  -  %d  -  %d  - %d",bir ->data, iki->data,uc ->data,dort ->data );
	
	return 0;
}
