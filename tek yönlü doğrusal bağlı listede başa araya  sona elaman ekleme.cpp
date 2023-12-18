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
	temp=start->next;
	free(start);
	start=temp;
}

void yazdir() {
    temp = start;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int number, adet = 0, secim, n;
    while (adet != 6) {
        printf("\nbasa eleman eklemek icin 1");
        printf("\nsona eleman eklemek icin 2");
        printf("\naraya eleman eklemek icin 3\n");
        printf("\nbastan eleman silmek icin 4\n");
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

