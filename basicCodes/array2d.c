#include <stdio.h>
/*çift dizi elemanlarının toplamını bastıran fonksiyon*/
int sumofeven(int a[], int n, int b[]){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 0){
            sum += a[i];
            b[i] = a[i];/*çift i değerlerini b[] kopyalayan satır*/
        }
    }
    return sum;
}
/*diziyi ekrana yazdıran fonksiyon*/
void printArray(int a[], int n){
    printf("dizi elemanlari\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
/*dizi elemanları 0 a eşitleyen fonksiyon */
void sifirla(int a[], int n, int b[]){/**/
    for(int i = 0; i < n; i++){/*a[] dizisini b[2] ye kopyalar*/
        if(a[i]%2 == 1){
            b[i] = a[i];

        }
        else{
            b[i] = a[i];
        }
        a[i] = 0;/*a[] tum elemanlarını 0 a eşitler*/
    }
    return;
}
int main(){
    int a[] = {1,2,3,4,5,6,7};/*7 elemanlı tek boyutlu bir dizi*/
    int b[2][7] = {0};/*8x3 elemanlı 2boyutlu bir dizi*/
    printArray(a, 7);/*fonksiyonu çağırır*/
    printf("%d\n", sumofeven(a, 7, b[0]));/*fonksiyonun return değerini ekrana yazdırır*/
    sifirla(a, 7, b[1]);/*fonksiyonu çağırır*/
    printArray(b[0], 7);/*fonksiyonu çağırır*/
    printArray(b[1], 7);/*fonksiyonu çağırır*/
    printArray(a, 7);/*fonksiyonu çağırır*/
}
