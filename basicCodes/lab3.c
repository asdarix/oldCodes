  /*MUSTAFA SABRİ İNCE
 * kişinin kg cinsinden kilosunu ve santimetre(cm) cinsinden boyunu
 *  alarak vücut kitle indeksini bulan program */


#include <stdio.h>

int main ()
{
	
	float kg,boycm,boym,bmi;

	 printf("boyunuzu santimetre cinsinden veriniz:\n");//kullanıcının boyunu ister
	 scanf("%f",&boycm);
	 
	 printf("kilonuzu kilogram cinsinden giriniz:\n ");//kullanıcının kilosunu ister
	 scanf("%f",&kg);
	
	 boym = boycm/100;//cm olan boyu metreye çevirir 
	 
	 bmi = kg/(boym*boym);//vucut kitle indexini hesaplar
	 
	 printf("vermis oldugunuz degerler:\n\t boyunuz(metre):%.2f\n\tkilonuz (kg):%.2f\n\n",boym,kg);
	 printf("vucut kitle indexsiniz: %.2f \n\n",bmi);
	
	 if (30 <= bmi)
	 {
	    printf("vucut kitle indexsiniz obez");
	 }
	
	 else if ( 25<=bmi && bmi<= 29.9)
	 {
	    printf("vucut kitle indexsiniz sisman");
	 }
	
	 else if ( 18.5 <= bmi && bmi <= 24.9 )
	 {
	    printf("vucut kitle indexsiniz normal");
	 }
	
	 else 
	 {
	 printf("vucut kitle indexsiniz zayif");
	 }
	
	
	return 0;
}
