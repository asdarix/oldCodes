/*
    mustafa sabri ince
    bbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaa
    yazdıran program
*/
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    for(int i=0;i<10;++i){
        fork();    
    }
    if(pid==0){
        
        printf("B");
    }
    else if(pid>0){
        sleep(1);
        printf("a");
    }
    
    return 0;
}