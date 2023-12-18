#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};

struct node *teksayi(struct node *head , int key){
	struct node* node2=(struct node*)malloc(sizeof(struct node));
	node2->data=key;
	node2->next=head;
	return node2;
}

struct node *ciftsayi(struct node *head , int key){
	struct node* node3=(struct node*)malloc(sizeof(struct node));
	node3->data=key;
	node3->next=NULL;
	if(head==NULL){
		return node3;
	}
	struct node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=node3;
	return head;
}

void print(struct node*head){
	while(head!=NULL){
		printf(" %d ", head->data);
		head=head->next;
	}
	printf("NULL");
}









int main(){
	int key;
	struct node*head=NULL;
	printf("-1 girerek programi sonlandirablirsiniz \n");
	
	while(1){
		printf("bir sayi giriniz:");
		scanf(" %d ",&key);
		if(key==-1){
			break;
		}
		if(key%2==1){
			head=teksayi(head,key);
		}
		else{
			head=ciftsayi(head,key);
		}
		
	}
	
	print(head);
	
	while(head!=NULL){
		struct node *temp=head;
		head=head->next;
		free (temp);
	}
	
	
	
	
	
	
	return 0;
}
