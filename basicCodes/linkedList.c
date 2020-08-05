/* mustafa sabri ince
 * lab12.c
 * LinkedList
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct dugum{
    int data;
    struct dugum *sonraki;  /* bir sonraki dugumun adresini tutar  */
    struct dugum *onceki;   /* bir onceki dugumun adresi           */
} Dugum;

Dugum bas, son;             /* listedeki ilk ve son dugumler    */   

/* listeyi baslatir */
int listeyi_baslat(){
    /* Bu fonksiyonda herhangi bir degisiklik yapmaniz gerekmiyor. */
    
    /* listenin basi    */
    bas.data = INT_MIN;
    bas.sonraki= &son;
    bas.onceki= NULL;
    
    /* listenin sonu (kuyrugu) */
    son.data = INT_MAX;
    son.sonraki = NULL;
    son.onceki = &bas; 
    return 1; 
}

/*
 * verilen dugumu listede uygun yere ekler
 */
int dugum_ekle(Dugum *n){
	Dugum *temp1;
	Dugum *temp2;
	temp1 = &bas;
	while((temp1->data) < (n->data)){
		temp1 = temp1->sonraki;
	}
	temp2=temp1->onceki;
    temp2->sonraki = n; 
    temp1->onceki= n;
    n->sonraki = temp1;
    n->onceki =temp2;
    return 0;
}

/* 
 * listede bulunan dugumleri bastan baslayarak yazdirir.
 */
void dugumleri_yazdir(){
    Dugum *temp;
    temp = &bas;
    while(temp != NULL){
		printf("%d\n", temp->data );
		temp = temp->sonraki;
	}
}

/* 
 * Yeni bir dugum icin hafiza alani olusturup 
 * data degerini verilen dataya esitler.
 * Olusturulan dinamik hafizanin adresini (pointeri) dondurur.
 */
Dugum *yeni_dugum(int data){
    Dugum *alan = (Dugum *) malloc (sizeof(Dugum));
	alan->data =data;
    return alan;
}


int main(){
    /* bu fonksiyonda 
     * herhangi bir degisiklik yapmaniz gerekmiyor 
     */
    listeyi_baslat();
    dugum_ekle(yeni_dugum(5));
    dugum_ekle(yeni_dugum(3));
    dugum_ekle(yeni_dugum(6));
  
    dugumleri_yazdir(); /* ciktisi: -INT_MIN 3 5 6 INT_MAX  */
   
   
    /* Program zaten sonlaniyor 
     * ama yinede ayrilan dinamik hafizayi serbest birakalim */
    Dugum *temp = bas.sonraki, *temp2;
    while(temp != NULL && temp != &bas && temp != &son){
        temp2 = temp;
        temp = temp->sonraki;
        free(temp2);
    }
    return 0;
}


