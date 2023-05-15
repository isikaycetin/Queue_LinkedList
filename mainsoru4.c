#include <stdio.h>
#include <stdlib.h>

// Kuyruk yap�s�
struct Queue {
    int data;
    struct Queue* next;
};
// front ve rear isimli iki i�aret�i tan�mlan�d�k.front, kuyru�un ba��n� (ilk eleman�n�) g�sterirken, rear kuyru�un sonunu (son eklenen eleman�n�) g�sterir.

struct Queue* front = NULL;    // Ba�lamgi�ta bo� oldu�u i�in NULL dedik.
struct Queue* rear = NULL;

// Kuyru�a eleman ekleme fonksiyonu
void enqueue(int data) {
	
	//Yeni bir d���m olu�turulur ve data de�eri bu d���me atan�r. next i�aret�isi NULL olarak ayarlan�r. Ard�ndan, kuyruk bo� ise, yeni d���m hem front hem de rear olarak ayarlan�r.De�ilse rear next e ba�lan�r. 
	
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
    if(front == NULL) {  //Bo�sa kuyruk bo� yazs�n.
        printf("Kuyruk bos.\n");
        return;
    }
    // E�er kuyruk sadece bir elemandan olu�uyorsa (front ve rear ayn� d���m� g�steriyorsa), front ve rear de�erleri NULL olsun.
    
    if(front == rear) {
        front = rear = NULL;
        
    // Degilse front i�aret�isi bir sonraki d���me ge�sin.    
    } else {                        
        front = front->next;
    }
}

// Kuyru�u g�r�nt�leme fonksiyonu
void display() {
    struct Queue* temp = front;        // temp ad�nda ge�ici bir i�aret�i olu�turulur ve ba�lang��ta bu i�aret�iye front atamas� yap�l�r.
    if(front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    while(temp != NULL) {
        printf("%d ",temp->data);     // temp i�aret�isindeki veriyi ekrana yazd�r�r ve temp i�aret�isini bir sonraki elemana ta��r.
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
            default:                                                  // Gecersiz Secim 4 harici say� bas�ld�ysa.  
                printf("Gecersiz secim.\n");
        }
    }
    return 0;
}


