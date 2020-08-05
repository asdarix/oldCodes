/*
 * atm.c
 * Tek bir kullanicinin hesabini tutan bank atm programi
 * Mustafa sabri ince
 * 18120205039 medeniyet ID
 */

#include <stdio.h>

const int PSWRD = 1234;         /*Kullanicinin sifresi*/
const int INIT_BALANCE = 100;   /* baslangic bakiye */

int main(){
	int islem,para;//işlem numarası , kullancının girdiği miktar
	int sifre;//kullanıcının girdiği şifre
	int yenibakiye;//son durumdaki bakiye
	
	printf("merhaba bankaniza hosgeldiniz\n");
	printf("lutfen sifrenizi giriniz :");
	scanf("%d",&sifre);
	
	if (sifre != PSWRD)//eğer yanlış şifre girilirse program sonlanır
	{
		printf("yanlis sifre girdiginiz icin program kapatiliyor");
	}
	else {//eğer şifre doğruysa kullanıcının yapacagı işlemi sorar
		printf("Yapicaginiz islemi secin\n 1 para yatirmak\n 2 para cekmek\n 3 hesap bakiyenizi gormek\n\n  ");
		scanf("%d", &islem);

		switch (islem) // işlem seçimini yaptırır
		{
			case 1:
				printf("yatirmak istediginiz miktari giriniz\n");
				scanf("%d", &para);
				
				if (para < 0)
					printf("hatali giris yaptiniz");

				else
				{
					yenibakiye = INIT_BALANCE + para;
					printf("yeni bakiyeniz %d", yenibakiye);
				}
				break;

			case 2:
				printf("cekmek istediginiz miktari giriniz\n");
				scanf("%d", &para);

				if (para > INIT_BALANCE)
					printf("hesabinizda yeteri kadar para bulunmamaktadir");

				if (para < 0)
					printf("hatali giris yaptiniz");

				if (para > 0 && INIT_BALANCE > para)
				{
					yenibakiye = INIT_BALANCE - para;
					printf("yeni bakiyeniz %d", yenibakiye);
				}
				break;
			case 3:
				printf("bakiyeniz %d ", INIT_BALANCE);
				break;

			default: // kullanici 1,2,3 dışında bir değer girerse hata mesajı verir
				printf("hatali giris yaptiniz");

		}
	}
	return 0;
}
