#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
	struct node * prew;  //bi önceki düðümü gösterir
};

struct node * next=NULL;
struct node * start=NULL;
struct node * temp=NULL;
struct node * prew=NULL;
struct node * temp2=NULL;

void basaEkle(int sayi){
	
	struct node * eleman =(struct node *)malloc(sizeof(struct node));	
	eleman->prew=NULL;
	eleman->data=sayi;
	if(start==NULL){
	
		start=eleman;
		start->next=NULL;
	
	}
	else{
		eleman->next=start;
		start=eleman;
		
	}
}

void sonaEkle(int sayi){
	
	struct node * eleman =(struct node *)malloc(sizeof(struct node));	
	eleman->data=sayi;
	eleman->next=NULL;
	
	if(start==NULL){
	
		start=eleman;
		start->next=NULL;
		start->prew=NULL;
	
	}
	else{
		if(start->next==NULL){
			start->next=eleman;
			eleman->prew=start;
		}
		else{
			temp=start;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=eleman;
			eleman->prew=temp;
		}
	
		
	}
}

void listele(){
	
	if(start==NULL){
		printf("liste bos");
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			
			printf(" %d ->",temp->data);
			temp=temp->next;
		}
		printf(" %d ",temp->data);
	}
}

int main(){
	while(1){
		
		int sayi,secim;
		printf("\n1 --> basa eleman ekle \n");
		printf("2 --> sona eleman ekle \n");
		printf("3 --> bastan eleman silme \n");
		printf("4 --> sondan eleman silme \n");
		printf("5 --> eleman sayisi \n");
		printf("6 --> eleman toplami \n");
		printf("7 --> listele \n");
		printf("seciminizi yapin \n");
		scanf("%d",&secim);
		switch(secim){
			
			case 1: printf("basa eklenecek sayi :");
			scanf("%d",&sayi);
			basaEkle(sayi);
			break;
			
			case 2: printf("sona eklenecek sayi :");
			    scanf("%d",&sayi);      
				sonaEkle(sayi);
				break;
			
			case 7: listele();
			break;
		}
		
	
	}
	
	
	
	
	return 0;
}
