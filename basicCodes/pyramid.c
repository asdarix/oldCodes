//MUSTAFA SABRİ İNCE
//piramit yazdıran program
//lab5a

#include <stdio.h>

int main(){
	
	int n;//kullanıcının girecegi sayı
	
	printf("sayiyi giriniz\n");
	scanf("%d",&n);
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			printf("%d",i);
			}
	    printf("\n");
	}
	
	return 0;
}

