//mustafa sabri ince
//2kişilik oyun iyi eğlenceler

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int puan1=0,puan2=0;
	int el2=0,el1=0;
	
	while(puan1<=100 && puan2<=100)
	{
		int b=1;
	      
		while (b == 1) {

			int a;
			int deger;

			printf("player1 zar atmak istiyor musun? 1 2\n");
			scanf("%d", &deger);
			if (deger == 1) {
				a = rand() % 6 + 1;
				if (a == 1) {
					printf("tuh 1 geldi\n");
					el1 = 0;
					b = 2;
				}
				else {
					el1 += a;
					printf("cikan sayi %d\n", a);
				}
			}
			else {
				puan1 = el1 + puan1;
				el1 = 0;
				b = 2;
			}
		}
		while (b == 2) {

			int a;
			int deger;

			printf("player2 zar atmak istiyor musun? 1 2\n");
			scanf("%d", &deger);

			if (deger == 1) {

				a = rand() % 6 + 1;
				if (a == 1) {
					printf("tuh 1 geldi\n");
					el2 = 0;
					b = 1;
				}
				else {
					el2 += a;
					printf("cikan sayi %d\n", a);
				}
			}
			else {
				puan2 += el2;
				el2 = 0;
				b = 1;
			}

		}

	    printf("puan1: %d ,puan2: %d\n",puan1,puan2);
    }
    if(puan1<puan2)
		printf("ikinci oyuncu kazandı");
    else
		printf("birinci oyuncu kazandı");
   
    return 0;
}
