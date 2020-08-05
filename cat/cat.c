/*
  Mustafa Sabri İnce
  Proje.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*dosyadan aldığı metinleri stdin e yazdırır*/
void okuma(FILE *f, int ops);
/*bir dosyadan aldığı metinleri işaret edilen
 * dosyaya kopyalar kopyalanan dosya sıfırlanır*/
void kopyalama(FILE *f, FILE *g, int ops);
/*stdinden input alarak bir metin belgesi yazdırır*/
void yazma(FILE *f, int ops);

int main(int argc, char **argv)
{
	int a= 1;/*yazma fonksiyonu için kontrol*/
	int ops= 0;/*opsiyonun default durumu*/
	if(0== strcmp(argv[1], "-n")){/*opsiyon -n için*/
		ops= 1;
		a++;
	}
	if(0== strcmp(argv[1],"-b")){/*opsiyon -b için*/
		ops= 2;
		a++;
	}
	if(strcmp(argv[1], "-h")== 0){/*opsiyon -h için*/
		printf( "dosyayi okutmak icin cat dosyaismi\n"
				"dosyayi kopyalamak icin cat dosya1 \">\"dosya2\n"
				"yeni bir dosya yazmak icin cat \">\" yeni dosyanin ismi\n");
		return 0;
	}
 	FILE *f;
	FILE *g;
	int kntr= 0;/*kontrol için atanmış değişken*/
	for(int i= 1; i< argc; i++){
		if(strcmp(argv[i], ">")== 0){/*işaretin nerede olduğunu ifade ediyor*/
			kntr= i;
			break;
		}
	}
	if (kntr== 0){/*okuma */
		for(int i= a; i< argc; i++){
			f= fopen(argv[i], "r");
			if(f== NULL){
				printf("dosya bulunamadi");
				return 0;
			}
			okuma(f, ops);
		}
	}
	else if(kntr== (argc- 1)){
		printf("hatali giris yaptiniz dogrusu\n"
				"cat dosyaismi1 > dosyaismi2");
	}
	else if(kntr== a){/*yazma*/
		f= fopen(argv[a+1], "w");
		if(f== NULL){
			printf("dosya bulunamadi");
			return 0;
		}
		yazma(f, ops);
	}
	else if(kntr== argc- 2){/*kopyalama*/
		g= fopen(argv[argc-1], "w");
		if(g== NULL){
			printf("dosya bulunamadi");
			return 0;
		}
		for(int i= a; i< kntr; i++){
			f= fopen(argv[i], "r");
			if(f== NULL){
				printf("dosya bulunamadi");
				return 0;
			}
			kopyalama(f, g, ops);
		}		
		fclose(g);
	}
	fclose(f);
	return 0;
}
/*dosyadan aldığı metinleri stdin e yazdırır*/
void okuma(FILE *f, int ops){
	char c;/*streamden alınan karakteri tutan değişken*/
	if(ops== 0){
		while((c= fgetc(f))!= EOF){
			printf("%c", c);
		}
	}
	else if(ops== 1){
		static int i= 1;/*sıralama yaparken sıra numarasını tutan değişken*/
		printf("\n%d-", i);
		while((c= fgetc(f))!= EOF){
			if(c== '\n'){
				printf("\n%d-", ++i);
			}
			else{
				printf("%c", c);
			}
		}
	}
	else if(ops== 2){
		static int i= 1;
		char s[250];
		printf("\n");
		while (fgets (s, 250, f)!= NULL){
			if(0== strcmp(s, "\n")){
				printf("\n");
			}
			else{
				printf("%d-", i++);
				printf("%s", s);
			}
		}
	}
}
/*bir dosyadan aldığı metinleri işaret edilen
 * dosyaya kopyalar kopyalanan dosya sıfırlanır*/
void kopyalama(FILE *f, FILE *g, int ops){
	char c;
	if(ops== 0){
		while((c= fgetc(f))!= EOF){
			fputc(c, g);
		}
	}
	else if(ops== 1){
		static int sayi1= 1;
		fprintf(g, "\n%d-", sayi1);
		while((c= fgetc(f))!= EOF){
			if(c!= '\n'){
				fputc(c, g);
			}
			else{
				fputc(c, g);/*\n koyduk*/
				sayi1++;
				fprintf(g, "%d-", sayi1);
			}
		}
	}
	else if(ops== 2){
		static int i= 1;
		char s[250];
		fprintf(f, "\n");
		while (fgets (s, 250, f)!= NULL){
			if(0== strcmp(s, "\n")){
				fprintf(g, "\n");
			}
			else{
				fprintf(g, "%d-", i++);
				fprintf(g, "%s", s);
			}
		}
	}
}
/*stdinden input alarak bir metin belgesi yazdırır*/
void yazma(FILE *f, int ops){
	char c;
	if(ops== 0){
		while((c= fgetc(stdin))!= EOF){
			fputc(c, f);
		}
	}
	else if(ops== 1){
	static int i= 1;
	fprintf(f, "\n");
	char dizi[250];
		while(fgets(dizi, 250, stdin)!= NULL){
			fprintf(f, "%d-", i++);
			fputs(dizi, f);
		}
	}
	else if(ops== 2){
		static int i= 1;
		char dizi[250];
		while(fgets(dizi, 250, stdin)!= NULL){
			if(0== strcmp(dizi, "\n")){
				fprintf(f, "\n");
			}
			else{
				fprintf(f, "%d-", i++);
				fputs(dizi, f);
			}
		}
	}
}
