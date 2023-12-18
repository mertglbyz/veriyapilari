#include<stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head= NULL;
struct node *temp=NULL;

void addhead(int number){
	
	struct node* add;
	add=(struct node*)malloc(sizeof(struct node));
	add->data=number;
	add->next=head;
	head=add;
	
}
void yazdir(){
	
	temp=head;
	while(temp->next!=NULL){
		
		printf(" %d ", temp ->data);
		temp=temp->next;
	}
	printf(" %d ", temp -> data);
}

int main(){
	
	int number;
	int adet=0;
	while(adet!=6){
		
	
	printf(" bir sayi girin:");
	scanf("%d",&number);
	addhead(number);
	adet++;

	}
		yazdir();
	return 0;
}
