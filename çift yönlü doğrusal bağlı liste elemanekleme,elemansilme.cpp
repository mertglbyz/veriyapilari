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
		start->prew=eleman;
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

void bastanSil(){
	
	if(start==NULL){
		printf("liste bos silinecek eleman yok");
		
	}
	else{
		if(start->next==NULL){
			free(start);
			start=NULL;
			
		}
		else{
			temp=start->next;
			free(start);
			temp->prew=NULL;
			start=temp;
		}
	}
}

void sondanSil(){
	
	if(start==NULL){
		printf("liste bos silinecek eleman yok");
		
	}
	else{
		if(start->next==NULL){
			free(start);
			start=NULL;
			
		}
		else{
			temp=start;
			while(temp->next->next!=NULL){
			temp=temp->next;	
			}
			temp2=temp;
			free(temp->next);
			temp2->next=NULL;
			
			
		}
	}
}

int elemanAdeti(){
	
	int adet=0;
	if(start==NULL){
		return 0;
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			adet++;
			temp=temp->next;
		}
		adet++;
		return adet;
	}
}

int dataToplami(){
	
	int toplam=0;
	if(start==NULL){
		return 0;
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			toplam+=temp->data;
			temp=temp->next;
		}
		toplam+=temp->data;
		return toplam;
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
		printf("6 --> data toplami \n");
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
			
			case 3: bastanSil();
			break;	
			
			case 4: sondanSil();
			break;	
			
			case 5: printf("eleman sayisi : %d",elemanAdeti());
			break;
			
			case 6: printf("data toplami : %d",dataToplami());
			break;
			
			case 7: listele();
			break;
		}
		
	
	}
	
	
	
	
	return 0;
}
