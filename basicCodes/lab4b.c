/*
	2018
 */


#include <stdio.h>

int main()
{
	long int n;
	printf("sayiyi giriniz\n");
	scanf("%ld",&n);
	
	while ( n!=1 ){
		if(n%2==1)
			n = (n*3)+1;
		else
	       n=n/2;
		
		printf("%ld\n",n);
    }
	return 0;
}

