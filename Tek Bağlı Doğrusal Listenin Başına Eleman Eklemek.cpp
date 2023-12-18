#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addhead(struct node *head, int key) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = head;
    head = temp;
    
    return head; 
}

int main() {
    // Program�n geri kalan�nda kullan�lacak olan struct node yap�s�n� tan�mla.
    struct node *head = NULL; // Ba�l� listemizin ba�lang�c�
    // Ba�l� listeye eleman eklemek i�in addhead fonksiyonunu kullanabilirsiniz.
    // �rne�in, head = addhead(head, 5);
    
    return 0;
}

