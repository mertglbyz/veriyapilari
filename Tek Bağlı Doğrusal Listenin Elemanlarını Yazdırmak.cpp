#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print(struct node* head) {
    if (head == NULL) {
        printf("Listede eleman yok\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    // Baðlý liste oluþturma iþlemleri
    struct node* head = NULL;
    // Baðlý liste elemanlarý eklenir, örneðin:
    // head = addhead(head, 1);
    // head = addhead(head, 2);
    // head = addhead(head, 3);
    // ...

    print(head); // Baðlý liste elemanlarýný ekrana yazdýrýr
    return 0;
}

