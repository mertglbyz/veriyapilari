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
    // Programýn geri kalanýnda kullanýlacak olan struct node yapýsýný tanýmla.
    struct node *head = NULL; // Baðlý listemizin baþlangýcý
    // Baðlý listeye eleman eklemek için addhead fonksiyonunu kullanabilirsiniz.
    // Örneðin, head = addhead(head, 5);
    
    return 0;
}

