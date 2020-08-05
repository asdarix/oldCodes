/* 
    mustafa sabri ince 
    abababababa
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
        if(pid > 0){
            printf("a");
            fflush(stdout);
            exit(0);
        }
        else{
            wait(NULL);
            printf("B");
            fflush(stdout);   
            pid = fork();
        }
    }
    return 0;
}
