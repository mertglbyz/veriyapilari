#include<stdio.h>
#include<stdlib.h>

// Baðlý liste düðümünü temsil etmek için yapý tanýmý
struct node{
	int data;
	struct node * next;
};

// Baðlý listenin baþýný, geçici elemaný, önceki elemaný ve son elemaný temsil eden global deðiþkenler
struct node * start=NULL;
struct node * temp=NULL;
struct node * prew=NULL;
struct node * last=NULL;

// Baðlý listeye baþa eleman eklemek için fonksiyon
void basaEkle(int sayi){
	struct node * eleman=(struct node *)malloc(sizeof(struct node));
	eleman->data=sayi;
	
	if(start==NULL){
		// Liste boþsa, yeni elemaný liste baþý yap ve döngüyü oluþtur
		start=eleman;
		start->next=start; 
	}
	else{
		// Liste doluysa, yeni elemaný ekleyip baðlarý güncelle
		temp=start;
		while(temp->next!=start){
			temp=temp->next;
		}
		temp->next=eleman;
		eleman->next=start;
		start=eleman;
	}
}

void sonaEkle(int sayi){
	struct node * eleman=(struct node *)malloc(sizeof(struct node));
	eleman->data=sayi;
	
	if(start==NULL){
		// Liste boþsa, yeni elemaný liste baþý yap ve döngüyü oluþtur
		start=eleman;
		start->next=start; 
	}
	else{
		// Liste doluysa, yeni elemaný ekleyip baðlarý güncelle
		temp=start;
		while(temp->next!=start){
			temp=temp->next;
		}
		temp->next=eleman;
		eleman->next=start;
		//burda start=eleman yok dikkat
	}
}

void bastanSil(){
	
	if(start==NULL){
		
		printf("liste bos, silinecek eleaman yok");
	}
	else{
		
		if(start->next==start){ //listede sadece tek bir eleman varsa
			free(start);
			start=NULL;
		}
		else{
			last=start;
			while(last->next!=start){
				last=last->next;
			}
			temp=start->next;
			free(start);
			last->next=temp;
			start=temp;
			
		}
	}
}

void sondanSil(){
	
	if(start==NULL){
		
		printf("liste bos, silinecek eleaman yok");
	}
	else{
		
		if(start->next==start){ //listede sadece tek bir eleman varsa
			free(start);
			start=NULL;
		}
		else{
			last=start;
			while(last->next->next!=start){  //dikkat
				last=last->next;
			}
			temp=last; //dikkat
			free(last->next);
			last->next=start;
			
		}
	}
}


// Baðlý listeyi ekrana yazdýrmak için fonksiyon
void listele(){
	
	if(start==NULL){
		printf("Liste bos\n");
	}
	else{
		// Liste doluysa, elemanlarý ekrana yazdýr
		temp=start;
		while(temp->next!=start){
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("%d ",temp->data);
	}
}

int main(){
	while(1){
	
	int secim,sayi;
	
	// Kullanýcýya seçenekleri göster
	printf("1-->Basa eleman eklemek icin\n");
	printf("2-->Sona eleman eklemek icin\n");
	printf("3-->Bastan eleman silmek icin\n");
	printf("4-->Sondan eleman silmek icin\n");
	printf("5-->Listele\n");
	
	// Kullanýcýdan bir seçim iste
	printf("Seciminizi yapin: ");
	scanf("%d",&secim);
	
	switch(secim){
		case 1: 
			// Baþa eleman eklemek için seçildiyse, kullanýcýdan bir sayý al ve baþa ekle
			printf("Baþa eklenecek sayi\n : ");
			scanf("%d",&sayi);
			basaEkle(sayi);
			break;
			
			case 2: 
			// sona eleman eklemek için seçildiyse, kullanýcýdan bir sayý al ve sona ekle
			printf("sona eklenecek sayi\n : ");
			scanf("%d",&sayi);
			sonaEkle(sayi);
			break;
			
			case 3: bastanSil();
			break;
			
			case 4: sondanSil();
			break;
			
		case 5: 
			// Listeyi görüntülemek için seçildiyse, listeyi ekrana yazdýr
			listele();
			break;
	}
	}

	return 0;
}

