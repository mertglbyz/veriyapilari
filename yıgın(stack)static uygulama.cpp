#include <stdio.h>
#include <stdlib.h>
#define size 10

struct stack {
    int arr[size];
    int top; //indis degeri
};
struct stack s1;

void elemanEkle(int sayi) { // push ()   burda parametre olarak int sayi da desek baska bisi de desek ayný anlama geliyor 
    if (s1.top == size - 1) {
        printf("stack doludur! \n");
    } else {
        s1.top++;
        s1.arr[s1.top] = sayi;
    }
}

void elemanCikar() { // pop()
    if (s1.top == -1) {
        printf("stack bostur, cikacak eleman yok!\n");
    } else {
        int cikanSayi = s1.arr[s1.top];
        s1.top--;
        printf("%d sayisi stackten cikarildi\n", cikanSayi);
    }
}

void print() {
    if (s1.top == -1) {
        printf("stack bos \n");
    } else {
        int i;
        for (i = s1.top; i >= 0; i--) {
            printf("%d\n", s1.arr[i]);
        }
    }
}

int main() {
    int secim, sayi;

    s1.top = -1; // Initialize the stack only once at the beginning

    while (1) {

        printf("\nstack\n");
        printf("1--> eleman ekle (push)\n");
        printf("2--> eleman cikar (pop)\n");
        printf("3--> yazdir (display)\n");
        printf("4--> cikis (exit)\n");
        printf("secimizi yapin: ");
        scanf("%d", &secim);
        switch (secim) {

        case 1:
            printf("eklenecek sayi: ");
            scanf("%d", &sayi);
            elemanEkle(sayi);
            break;

        case 2:
            elemanCikar();
            break;

        case 3:
            print();
            break;

        case 4:
            printf("programdan cikiliyor\n");
            return 0;
        }
    }
}

