/*mustafa sabri ince lab8.c

	fibonacci and palindrom
*/
#include <stdio.h>

int pal_yardimci(char str[], int bas, int son){
	if(bas>son){
		printf("palidromdur\n");
		return 0;
	}		
	else if(son%2==1){
		if(str[bas]==str[son]){
			pal_yardimci(str,bas+1,son-1);
		}
		else{
			printf("palidrom degildir\n");
		}
	}
	else{
		if(str[bas]==str[son]){
			pal_yardimci(str,bas+1,son-1);
		}
		else{
			printf("palidrom degildir\n");
		}
			
	}
	return 0;
}

/*istenilen kelimenin palidrom olup olmadıgını bulan fonksiyon*/
int palindrom(char str[]){
    int n;
    while(str[n]!='\0'){
		n++;
	}
		printf("uzunluk %d \n", n);
		pal_yardimci(str, 0, n-1);
	return 0;
}	


/*özyinelemeli palidrom bulucu*/
int fibonacci(int n){
	if(n== 1){
		return 1;
	}
	if(n== 0){
		return 0;
	}	
	else{
		n=fibonacci(n-1)+ fibonacci(n-2);
	}
	
	return n;
}
int fibonacci2(int n){
	int f2;
	int f1=1,f0=0;
	for(int a= n-1; a> 0; a--){
		f2= f1+ f0;
		f0= f1;
		f1= f2;
	}
	printf("dongulu fibonacci %d\n", f2);
	return f2;
}

int main(){
	int a= fibonacci(6);/*özyinelemeli fibonacci bulucu*/
	printf("ozyinelemeli fibonacci %d\n", a);
	palindrom("mustafa");/*istenilen kelimenin palidrom olup olmadıgını bulan fonksiyon*/
	fibonacci2(6);/*döngülü fibonacci bulucu*/
	return 0;
}
