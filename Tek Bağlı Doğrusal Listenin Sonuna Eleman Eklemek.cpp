#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *addlast(struct node *head,int key) {
struct node *temp = (struct node *)malloc(sizeof(struct node));
/* C++'ta struct node *temp = new node();
* �eklinde kullan�labilece�ini unutmay�n�z. */
temp -> data = key;
temp -> next = NULL;
struct node *temp2 = head;
/* A�a��daki while yap�s� traversal(dola�ma) olarak adland�r�l�r */
while(temp2 -> next != NULL)
temp2 = temp2 -> next;
temp2 -> next = temp;
return head;
}



int main() {
    // Program�n geri kalan�nda kullan�lacak olan struct node yap�s�n� tan�mla.
    struct node *head = NULL; // Ba�l� listemizin ba�lang�c�
    // Ba�l� listeye eleman eklemek i�in addhead fonksiyonunu kullanabilirsiniz.
    // �rne�in, head = addhead(head, 5);
    
    return 0;
}

