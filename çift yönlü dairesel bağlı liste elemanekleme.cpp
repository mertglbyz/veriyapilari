#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
	struct node * prew;
	
};

struct node * start=NULL;
struct node * temp=NULL;
struct node * temp2=NULL;
struct node * prew=NULL;


void basaEkle(int sayi){
	struct node * eleman=(struct node *)malloc(sizeof(struct node));
	eleman->data=sayi;
	
	if(start==NULL){
		start=eleman;
		start->next=start;
		start->prew=start;
	}
	else{
		if(start->next==start){
			start->next=eleman;
			start->prew=eleman;
			eleman->next=start;
			eleman->prew=start;
			start=eleman;
		}
		else{
			temp=start;
			while(temp->next!=start){
				temp=temp->next;
				
			}
			temp->next=eleman;
			eleman->prew=temp;
			eleman->next=start;
			start->prew=eleman;
			
			start=eleman;  //baðlama iþlemleri yapýldý
		}
	}
}

void sonaEkle(int sayi){
	struct node * eleman=(struct node *)malloc(sizeof(struct node));
	eleman->data=sayi;
	eleman->next=start;
	
	if(start==NULL){
		start=eleman;
		start->next=start;
		start->prew=start;
	}
	else{
		if(start->next==start){
			start->next=eleman;
			start->prew=eleman;
			eleman->next=start;
			eleman->prew=start;
			
		}
		else{
			temp=start;
			while(temp->next!=start){
				temp=temp->next;
				
			}
			temp->next=eleman;
			eleman->prew=temp;
			eleman->next=start;
			start->prew=eleman;
			
		}
	}
}

void bastanSil(){
	
	if(start==NULL){
		printf("liste bos silinecek eleman yok \n");
		
	}
	else{
		if(start->next==start){
			free(start);
			start=NULL;
		}
		else{
			temp=start;
			while(temp->next!=start){
				temp=temp->next;
			}
			temp2=start->next;
			free(start);
			temp->next=temp2;
			temp2->prew=temp;
			
			start=temp2;
		}
	}
}

void sondanSil(){
	
	if(start==NULL){
		printf("liste bos silinecek eleman yok \n");
		
	}
	else{
		if(start->next==start){
			free(start);
			start=NULL;
		}
		else{
			temp=start;
			while(temp->next!=start){
				temp=temp->next;
			}
			
			temp2=temp->prew; //önemli
			free(temp);
			temp2->next=start;
			start->prew=temp2;
			
		}
	}
}

void listele(){
	if(start==NULL){
		printf("liste bos");
		
	}
	else{
		temp=start;
		while(temp->next!=start){
			printf("%d->",temp->data);
			temp=temp->next;
		}
			printf("%d",temp->data);

	}
}

int main(){
	
	while(1){
		
		int sayi,secim;
		printf("\n1--> basa ekle \n");
		printf("\n2--> sona ekle \n");
		printf("\n3--> bastan sil \n");
		printf("\n4--> sondan sil \n");
		printf("\n5--> basa ekle \n");
		printf("\n6--> basa ekle \n");
		printf("\n7--> listele \n");
		printf("\n seciminizi yapiniz\n");
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
			
			case 3: bastanSil();
			break;
			
			case 4: sondanSil();
			break;
			
				
			
			case 7: listele();
			break;
		
		}

		}		
	}
	
	
	
	

