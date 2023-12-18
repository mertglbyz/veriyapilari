#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data;
	struct node* pointer;
};
struct node* head= NULL;
struct node* temp= NULL;

void addLast (int number){
	
	struct node* add;
	add= (struct node*)malloc(sizeof(struct node));
	add ->data= number;
	add ->pointer=NULL;
	
	if(head==NULL){
		head=add;
	}
	else{
		temp=head;
		while(temp->pointer!=NULL){
			temp=temp->pointer;
		}
		temp->pointer=add;
	}
}
void yazdir (){
	
	temp=head;
	while(temp->pointer!=NULL){
		printf(" %d ", temp -> data);
		temp=temp->pointer;
	}
	printf(" %d ",temp->data);
}

int main(){
	int adet=0;
	while(adet!=5){
		
	
	int number;
	printf("bir sayi girin");
	scanf("%d",&number);
	addLast(number);
	adet++;
}
	yazdir ();
	return 0;
} 
