#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void listinfo(struct node* head) {
    int i = 1;
    while (head != NULL) {
        printf("%d. Dugumunun Adresi = %p \n", i, (void *)head);
        printf("%d. Dugumunun verisi = %d \n", i, head->data);
        if (head->next != NULL) {
            printf("%d. Dugumunun Bagli Oldugu Dugumun Adresi= %p\n\n", i, (void *)(head->next));
        } else {
            printf("%d. Dugumunun Bagli Oldugu Dugumun Adresi= NULL\n\n", i);
        }
        head = head->next;
        i++;
    }
}

int main() {
    // Baðlý liste oluþtur ve listeyi görüntüle
    struct node node1, node2, node3;
    node1.data = 1;
    node1.next = &node2;
    node2.data = 2;
    node2.next = &node3;
    node3.data = 3;
    node3.next = NULL;

    listinfo(&node1); // Baðlý liste bilgilerini görüntüler
    return 0;
}

