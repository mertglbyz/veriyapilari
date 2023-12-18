#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *temp = NULL;

void addhead(int data) {
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    if (!eleman) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    eleman->data = data;
    eleman->next = start;
    start = eleman;
}

void addlast(int data) {
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    if (!eleman) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    eleman->data = data;
    eleman->next = NULL;

    if (start == NULL) {
        start = eleman;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = eleman;
    }
}

void addmiddle(int n, int data) {
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    if (!eleman) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    eleman->data = data;

    temp = start;
    while (temp->next != NULL && temp->next->data != n) {
        temp = temp->next;
    }

    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    if (!temp2) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    temp2 = temp->next;
    temp->next = eleman;
    eleman->next = temp2;
}

void bastanSil(){
	if(start!=NULL){
		
	temp=start->next;
	free(start);
	start=temp;
	}
	else{
		free(start);
	}
}
void sondanSil(){
	
	if(start->next!=NULL){
		temp=start;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
	else{
		bastanSil();
	}
}

void aradanSil(int veri) {
    temp = start;

    if (temp->data == veri) {
        bastanSil();
    } else {
        struct node *temp2;
        temp2 = (struct node *)malloc(sizeof(struct node));

        while (temp->next != NULL && temp->next->data != veri) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
        }
    }
}

void tersCevir(){
	struct node * temp2=NULL;
	struct node * prev= NULL;
	temp=start;
	while(temp!=NULL){
		temp2=temp->next;
		temp->next=prev;
		prev=temp;
		temp=temp2;
	}
	start=prev;
}

int elemanSay()
{
	int adet =0;
	if(start==NULL){
		return adet;
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


void yazdir() {
	if(start!=NULL){
		
	
    temp = start;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
  }
  else{
  	printf("eleman yok!!");
  }
  
  

}

int main() {
    int number, adet = 0, secim, n;
    while (adet != 6) {
        printf("\nbasa eleman eklemek icin 1\n");
        printf("\nsona eleman eklemek icin 2\n");
        printf("\naraya eleman eklemek icin 3\n");
        printf("\nbastan eleman silmek icin 4\n");
        printf("\nsondan eleman silmek icin 5\n");
        printf("\naradan eleman silmek icin 6\n");
        printf("\nelemanlari ters cevirmek icin 7\n");
        printf("\neleman adeti icin 8\n");
        printf("\nseciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("\nbasa eklenecek elemanin degeri: ");
                scanf("%d", &number);
                addhead(number);
                yazdir();
                break;

            case 2:
                printf("\nsona eklenecek elemanin degeri: ");
                scanf("%d", &number);
                addlast(number);
                yazdir();
                break;

            case 3:
                printf("hangi sayidan once: ");
                scanf("%d", &n);
                printf("\naraya eklenecek elemanin degeri: ");
                scanf("%d", &number);
                addmiddle(n, number);
                yazdir();
                break;
            
			case 4:    
			bastanSil();
			yazdir();
			break;
			
			case 5:    
			sondanSil();
			yazdir();
			break;
			
			case 6:    
			printf("aradan silinecek elemanin degeri :");
			scanf(" %d ",&number);
			aradanSil(number);
			yazdir();
			break;
			
			case 7:    
			printf("elemanlar ters cevriliyor.. :");
			tersCevir();
			yazdir();
			break;
			
			case 8:    
			printf("eleman adedi .. %d :",elemanSay());
			yazdir();
			break;
        }
        adet++;
    }

    // Free allocated memory
    temp = start;
    while (temp != NULL) {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

