#include <stdio.h>
#include <stdlib.h>

// Kuyruk yapýsý
struct Queue {
    int data;
    struct Queue* next;
};
// front ve rear isimli iki iþaretçi tanýmlanýdýk.front, kuyruðun baþýný (ilk elemanýný) gösterirken, rear kuyruðun sonunu (son eklenen elemanýný) gösterir.

struct Queue* front = NULL;    // Baþlamgiçta boþ olduðu için NULL dedik.
struct Queue* rear = NULL;

// Kuyruða eleman ekleme fonksiyonu
void enqueue(int data) {
	
	//Yeni bir düðüm oluþturulur ve data deðeri bu düðüme atanýr. next iþaretçisi NULL olarak ayarlanýr. Ardýndan, kuyruk boþ ise, yeni düðüm hem front hem de rear olarak ayarlanýr.Deðilse rear next e baðlanýr. 
	
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = data;
    temp->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// Kuyruktan eleman silme fonksiyonu
void dequeue() {
    if(front == NULL) {  //Boþsa kuyruk boþ yazsýn.
        printf("Kuyruk bos.\n");
        return;
    }
    // Eðer kuyruk sadece bir elemandan oluþuyorsa (front ve rear ayný düðümü gösteriyorsa), front ve rear deðerleri NULL olsun.
    
    if(front == rear) {
        front = rear = NULL;
        
    // Degilse front iþaretçisi bir sonraki düðüme geçsin.    
    } else {                        
        front = front->next;
    }
}

// Kuyruðu görüntüleme fonksiyonu
void display() {
    struct Queue* temp = front;        // temp adýnda geçici bir iþaretçi oluþturulur ve baþlangýçta bu iþaretçiye front atamasý yapýlýr.
    if(front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    while(temp != NULL) {
        printf("%d ",temp->data);     // temp iþaretçisindeki veriyi ekrana yazdýrýr ve temp iþaretçisini bir sonraki elemana taþýr.
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int secim, eleman;
    while(1) {
        printf("\nLutfen asagidaki islemlerden birini seciniz:\n");
        printf("1. Ekleme\n");
        printf("2. Silme\n");
        printf("3. Goruntuleme\n");
        printf("4. Cikis\n");
        printf("\nSeciminiz: ");
        scanf("%d",&secim);

        switch(secim) {
            case 1:                                                      // Ekleme
                printf("Eklemek istediginiz degeri giriniz: ");
                scanf("%d",&eleman);
                enqueue(eleman);
                break;
            case 2:                                                     // Silme        
                dequeue();
                break;
            case 3:                                                  // Goruntuleme
                display();
                break;
            case 4:                                                   // Cikis
                exit(0);
            default:                                                  // Gecersiz Secim 4 harici sayý basýldýysa.  
                printf("Gecersiz secim.\n");
        }
    }
    return 0;
}


