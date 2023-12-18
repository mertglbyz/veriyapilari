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
    // Ba�l� liste olu�turma i�lemleri
    struct node* head = NULL;
    // Ba�l� liste elemanlar� eklenir, �rne�in:
    // head = addhead(head, 1);
    // head = addhead(head, 2);
    // head = addhead(head, 3);
    // ...

    print(head); // Ba�l� liste elemanlar�n� ekrana yazd�r�r
    return 0;
}

