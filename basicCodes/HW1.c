#include <stdio.h>
#define compare(x,y) x>y ? 1 : 0

int main(){
	int a[10],b[10];
	int sum=0;
	int control=0;
	for(int i=0;i<10;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<10;++i)
		scanf("%d",&b[i]);
	
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			if(compare(a[i],b[j])){
				++control;
			}	
		}
		if(control<10)
			control=0;
		else
			++sum;		
	}
	printf("%d\n",sum);

	return 0;
}
