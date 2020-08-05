//ls -1 | cut -d'.' -f1 | sort | uniq | tee dirents
/*mustafa sabri ince*/
#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int p1[2]; // pipe between ls | cut
    int p2[2]; // pipt between cut and sort
    int p3[2]; // pipt between sort and uniq
    int p4[2]; // pipt between uniq and tee
	
	pid_t pros1;
	pid_t pros2;
	pid_t pros3;
	pid_t pros4;
	
	pipe(p1);
	pros1= fork();
    
    if (pros1==0){
		pipe(p2);
		pros2= fork();
		
		if(pros2==0){
			pipe(p3);
			pros3= fork();
			
			if(pros3==0){
				pipe(p4);
				pros4= fork();
				
				if(pros4==0){
					dup(p4[1]);
					execlp("uniq", "uniq", (char *)NULL);
					exit(-1);
				}
				if(pros4>0){
					dup(p4[0]);
					execlp("tee", "tee", "dirents",(char *)NULL);
					exit(-1);
				}
			}
			if(pros3>0){
				dup(p3[0]);
				execlp("sort", "sort",(char *)NULL);
				exit(-1);
			}
		}
			
		if(pros2>0){
			dup (p1[0]); // dup stdin to p2's in
            wait(NULL); // wait for child to finish
            dup (p2[1]); // dup stdout to p1's out
            close (p2[0]); // close p1's in 
			execlp("cut", "cut", "-f1", "-d.", (char *)NULL);
			exit(-1);
		}
	}

	if(pros1>0){
        dup (p1[1]); // dup stdout to p2's out
        close (p1[0]); // close p1's in
        execlp ("ls", "ls", "-1", (char *)NULL); // execute command
        exit (-1);
	}
        
    return 0;
}
