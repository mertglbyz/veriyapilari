#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *temp = NULL;
struct node *front = NULL;   // bastaki düðümü tutar
struct node *rear = NULL;    // kuyruktaki son düðümü tutar

void push(int veri) {
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data = veri;

    if (front == NULL) {
        front = eleman;
        front->next = front;
        rear = eleman;
        rear->next = NULL;
    } else if (front->next == front) {
        rear->next = eleman;
        rear = eleman;
        rear->next = front;
        front->next = rear;
    } else {
        rear->next = eleman;
        rear = eleman;
        rear->next = front;
    }
}

void pop() {
    if (front == NULL) {
        printf("queue(kuyruk) bostur\n");
    } else {
        printf("%d elemani kuyruktan cikartildi\n", front->data);
        temp = front->next;
        free(front);
        front = temp;

        if (front == NULL) {
            rear = NULL;
        }
    }
}

void print() {
    if (front == NULL) {
        printf("queue(kuyruk) bostur\n");
    } else {
        temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int sayi, secim;
    while (1) {
        printf("\nQUEUE(KUYRUK)\n");
        printf("1--eleman ekle(push)\n");
        printf("2--eleman silme(pop)\n");
        printf("3--yazdir(print)\n");
        printf("4--CIKIS\n");
        printf("seciminizi yapin\n");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("sayi girin: ");
                scanf("%d", &sayi);
                push(sayi);
                break;

            case 2:
                pop();
                break;

            case 3:
                print();
                break;

            case 4:
                return 0;
        }
    }

    return 0;
}

