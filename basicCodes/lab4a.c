/*
 * 
 * MUSTAFA SABRİ İNCE 
 * 18120205039
 * 100 DEFALIK ÇUBUK KIRMA SİMULASYONU
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int a = 1;//döngünün dönme sayısı için
    double kisaLen;//kısa kenar
	double toplam;//n tane kenar uzunlugunun toplamı 
		
		while (a<=100)
		{
				int r = rand();
				  
				/*[0-1] araliginda rastgele nokta bulur*/
				double point = (double)r/RAND_MAX;
				
				/*kisa kenar uzunlugunu hesaplar*/
				kisaLen = (point < 0.5)? point: 1-point; 
	
				toplam = kisaLen + toplam;//kısa kenarların toplamı
	
				a++;
		}
	
	printf(" ortalama deger %.3lf",toplam/100);// döngüyü 100 defa tekrarladıgım için 100 e böldüm

	

	return 0;
}

