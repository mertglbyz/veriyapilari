#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *addlast(struct node *head,int key) {
struct node *temp = (struct node *)malloc(sizeof(struct node));
/* C++'ta struct node *temp = new node();
* þeklinde kullanýlabileceðini unutmayýnýz. */
temp -> data = key;
temp -> next = NULL;
struct node *temp2 = head;
/* Aþaðýdaki while yapýsý traversal(dolaþma) olarak adlandýrýlýr */
while(temp2 -> next != NULL)
temp2 = temp2 -> next;
temp2 -> next = temp;
return head;
}



int main() {
    // Programýn geri kalanýnda kullanýlacak olan struct node yapýsýný tanýmla.
    struct node *head = NULL; // Baðlý listemizin baþlangýcý
    // Baðlý listeye eleman eklemek için addhead fonksiyonunu kullanabilirsiniz.
    // Örneðin, head = addhead(head, 5);
    
    return 0;
}

