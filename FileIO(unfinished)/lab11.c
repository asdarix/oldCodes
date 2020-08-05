/* 
 * lab11.c
 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 
 * no, isim, soyisimle verilen kaydi f dosyasinin sonuna ekler 
 */
void ekle(FILE *f, char *no, char *isim, char *soyisim){		
	fprintf(f,"%s\t%s\t%s\n",no,isim,soyisim);
    return;
}

/* 
 * numaralarinin baslangic n karakteri no'ya esit olan
 *  kayitlarin bilgilerini listeler 
 */
int no_ile_ara(FILE *f, char *no, int n){
	char l[150], l2[150];
	while(fgets(l, 150, f) != NULL){
       strncpy(l2, l, 150);
       char *pid = strtok(l,"\t");
       if(!strncmp(no,pid,n)){
           printf("Id: %.10s\n", pid);
           printf("First Name: %.40s\n", strtok(NULL, "\t"));
           printf("Last Name: %.40s\n", strtok(NULL, "\t"));
       }
    }
    return 0;
}

/* 
 * isimlerinin baslangic n karakteri isim'e esit olan 
 * kayitlarin bilgilerini listeler 
 */
int isim_ile_ara(FILE *f, char *isim, int n){
	char l[150], l2[150];
	while(fgets(l, 150, f)!= NULL){
       strncpy(l2, l, 150);
       char *pid = strtok(l,"\t");
       if(!strncmp(isim,pid,n)){
           printf("Id: %.10s\n", pid);
           printf("First Name: %.40s\n", strtok(NULL, "\t"));
           printf("Last Name: %.40s\n", strtok(NULL, "\t"));
       }
    }
    return 0;
}


/* 
 * soyisimlerinin baslangic n karakteri soyisim'e esit olan 
 * kayitlarin bilgilerini listeler 
 */
int soyisim_ile_ara(FILE *f, char *soyisim, int n){
    char l[150], l2[150];
	while(fgets(l, 150, f)!= NULL){
       strncpy(l2, l, 150);
       char *pid = strtok(l,"\t");
       if(!strncmp(soyisim,pid,n)){
           printf("Id: %.10s\n", pid);
           printf("First Name: %.40s\n", strtok(NULL, "\t"));
           printf("Last Name: %.40s\n", strtok(NULL, "\t"));
       }
    }
    return 0;
}


/* dosyayi acar ve 
 * verilen inputlari yorumlayarak ilgili fonksiyonu cagirir 
 * sonra dosyayi kapatarak programdan cikar*/
int main(int argc, char *argv[])
{
    char a[5]={"ekle"};
    char b[3]={"no"};
    char c[6]={"isim"};
    char d[9]={"soyisim"};
    FILE *f = fopen("students.txt","a+");
    if(0==strcmp(argv[1],a)){
		ekle(f,argv[2],argv[3],argv[4]);
	}
    else if(0==strcmp(argv[1],b)){
		no_ile_ara(f,argv[2],strlen(argv[2]));
	}
    else if(0==strcmp(argv[1],c)){
		isim_ile_ara(f,argv[3],strlen(argv[3]));
	}
    else if(0==strcmp(argv[1],d)){
		soyisim_ile_ara(f,argv[4],strlen(argv[4]));
	}
    fclose(f);
    return 0;
}
