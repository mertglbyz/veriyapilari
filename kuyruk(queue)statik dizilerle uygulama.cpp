#include <stdlib.h>
#include <stdio.h>
#define SIZE 5

int arr[SIZE];
int front = -1, rear = -1;

void push(int veri) {
    if (rear == SIZE - 1) {
        printf("queue (kuyruk) doludur\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = veri;
    }
}

void pop() {
    if (front == -1 || front > rear) {
        printf("queue(kuyruk) bostur\n");
        front = -1;
        rear = -1;
    } else {
        front = front + 1;
    }
}

void print() {
    if (front == -1) {
        printf("queue(kuyruk) bos\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int secim, sayi;
    while (1) {
        printf("\n1-- push islemi\n");
        printf("2-- pop islemi\n");
        printf("3-- print islemi\n");
        printf("4-- CIKIS islemi\n");
        printf("seciminizi yapiniz\n");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("sayi girin\n");
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
}

