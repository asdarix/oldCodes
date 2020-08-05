/* 
    mustafa sabri ince 
    abcabcabc
    yazdıran program
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h>
  
int main() 
{ 
    pid_t pid=fork();
    pid_t pid2;
    for(int i=0;i<5;++i){   
        if(pid == 0){
            sleep(2);
            printf("B");
            fflush(stdout);
            exit(0);
        }
        else{
            pid2=fork();
            if(pid2 > 0){
                printf("a");
                fflush(stdout);
                exit(1);
            }
            else{
                sleep(3);
                printf("c");
                fflush(stdout);
                
                pid = fork();
            }
        }
    }
    return 0;
}
