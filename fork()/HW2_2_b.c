/* 
    mustafa sabri ince 
    cccccccccccaaaaaaaaaaaaaaaaaBBBBBBBBBBBBBBBBBB
    yazdıran program
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h>
  
int main() 
{ 
    for(int i=0;i<8;++i)
        fork();

    pid_t pid = fork();
    pid_t pid2;
    if(pid==0){
        sleep(2);
        printf("B");
        fflush(stdin);
    }
    else{
        pid2=fork();
        
        if(pid2==0){
            
            printf("c");
            fflush(stdin);
        }

        else
        {
            sleep(1);
            printf("a");
            fflush(stdin);
            
        }    
    }
    

}
