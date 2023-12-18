#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node*next;
};

struct node* start=NULL;
struct node* temp=NULL;

void addhead(int data){
	struct node* eleman;
	eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data=data;
	eleman->next=start;
	start=eleman;
}
void addlast(int data){
	
	struct node*eleman;
	eleman=(struct node*)malloc(sizeof(struct node));
	eleman ->data=data;
	eleman->next=NULL;
	
	if(start==NULL){
		start=eleman;
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=eleman;
	}
}
void addmiddle(int n, int data){
	struct node*eleman;
	eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data=data;
	
	temp=start;
	while(temp->next->data!=n){
		
		temp=temp->next;
	}
	struct node*temp2;
	temp2=(struct node*)malloc(sizeof(struct node));
	temp2=temp->next;
	temp->next=eleman;
	eleman->next=temp2;
}
void yazdir(){
	temp=start;
	while (temp->next!=NULL){
		printf(" %d ", temp->data);
		temp= temp->next;
	}
		printf(" %d ", temp->data);

}

int main (){
	int number,adet=0, secim,n;
	while( adet!=6 ){
		printf(" \nbasa eleman eklemek icin 1 \n");
		printf("\nsona eleman eklemek icin 2 \n");
		printf("araya eleman eklemek icin 3\n");
        printf("\nseciminizi yapin\n");
        scanf("%d",&secim);
        
        switch(secim){
        	case 1: printf("\nbasa eklenecek elemanin degeri: \n");
        	scanf(" %d ",&number);
        	addhead(number);
        	yazdir();
        	break;
        	
        	case 2: printf("\nsona eklenecek elemanin degeri:");
        	scanf(" %d ",&number);
        	addlast(number);
        	yazdir();
        	break;
        	
        	case 3:  printf("hangi sayidan once");
			scanf(" %d ",& number); 
			printf("\naraya eklenecek elemanin degeri:\n");
        	scanf(" %d ",&number);
        	addmiddle(n,number);
        	yazdir();
        	break;
        	
		}
		adet++;

	}
	
	
	
	return 0;
}
