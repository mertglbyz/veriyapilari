#include<stdio.h>
#include<stdlib.h>

// Ba�l� liste d���m�n� temsil etmek i�in yap� tan�m�
struct node{
	int data;
	struct node * next;
};

// Ba�l� listenin ba��n�, ge�ici eleman�, �nceki eleman� ve son eleman� temsil eden global de�i�kenler
struct node * start=NULL;
struct node * temp=NULL;
struct node * prew=NULL;
struct node * last=NULL;

// Ba�l� listeye ba�a eleman eklemek i�in fonksiyon
void basaEkle(int sayi){
	struct node * eleman=(struct node *)malloc(sizeof(struct node));
	eleman->data=sayi;
	
	if(start==NULL){
		// Liste bo�sa, yeni eleman� liste ba�� yap ve d�ng�y� olu�tur
		start=eleman;
		start->next=start; 
	}
	else{
		// Liste doluysa, yeni eleman� ekleyip ba�lar� g�ncelle
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
		// Liste bo�sa, yeni eleman� liste ba�� yap ve d�ng�y� olu�tur
		start=eleman;
		start->next=start; 
	}
	else{
		// Liste doluysa, yeni eleman� ekleyip ba�lar� g�ncelle
		temp=start;
		while(temp->next!=start){
			temp=temp->next;
		}
		temp->next=eleman;
		eleman->next=start;
		//burda start=eleman yok dikkat e�er olursa ba�a eleman ekler
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

int elemanSay(){
	int adet=0;
	if(start==NULL){
		return 0;
	}
	else{
		temp=start;
		while(temp->next!=start){
			adet++;
			temp=temp->next;
		}
		adet++;
	}
	return adet;
}

int dataToplam(){
	int toplam=0;
	if(start==NULL){
		return 0;
	}
	else{
		temp=start;
		while(temp->next!=start){
			toplam+=temp->data;
			temp=temp->next;
		}
		toplam+=temp->data;
	}
	return toplam;
}


// Ba�l� listeyi ekrana yazd�rmak i�in fonksiyon
void listele(){
	
	if(start==NULL){
		printf("Liste bos\n");
	}
	else{
		// Liste doluysa, elemanlar� ekrana yazd�r
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
	
	// Kullan�c�ya se�enekleri g�ster
	printf("1-->Basa eleman eklemek icin\n");
	printf("2-->Sona eleman eklemek icin\n");
	printf("3-->Bastan eleman silmek icin\n");
	printf("4-->Sondan eleman silmek icin\n");
	printf("5--> eleman adeti icin \n");
	printf("6-->data toplami icin \n");
	printf("7-->Listele\n");
	
	// Kullan�c�dan bir se�im iste
	printf("Seciminizi yapin: ");
	scanf("%d",&secim);
	
	switch(secim){
		case 1: 
			// Ba�a eleman eklemek i�in se�ildiyse, kullan�c�dan bir say� al ve ba�a ekle
			printf("Ba�a eklenecek sayi\n : ");
			scanf("%d",&sayi);
			basaEkle(sayi);
			break;
			
			case 2: 
			// sona eleman eklemek i�in se�ildiyse, kullan�c�dan bir say� al ve sona ekle
			printf("sona eklenecek sayi\n : ");
			scanf("%d",&sayi);
			sonaEkle(sayi);
			break;
			
			case 3: bastanSil();
			break;
			
			case 4: sondanSil();
			break;
			
			case 5: printf("eleman adeti : %d",elemanSay());
			break;
			
			case 6: printf("data toplami : %d",dataToplam());
			break;
			
		    case 7: 
			// Listeyi g�r�nt�lemek i�in se�ildiyse, listeyi ekrana yazd�r
			listele();
			break;
	}
	}

	return 0;
}

