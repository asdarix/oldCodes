
//ls -1 | cut -d'.' -f1 | sort | uniq | tee dirents
/*mustafa sabri ince*/
#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pipe_fds[2];

    pipe2(pipe_fds, O_CLOEXEC);

    if (!fork()){
        
        dup2(pipe_fds[1], 1);

        execlp("ls", "ls", "-1", (char *)NULL);
        exit(-1);
    }
    else
    {
		if(!fork())
		{
			
			dup2(pipe_fds[0], 0);
			execlp("cut", "cut", "-f1", "-d.", (char *)NULL);
			exit(-1);
		}
		else{
			if(!fork())
			{	
				dup2(pipe_fds[1], 1);
				execlp("sort", "sort",(char *)NULL);
				exit(-1);
			}
			else{
				if(!fork())
				{
					dup2(pipe_fds[0], 0);
					execlp("uniq", "uniq", (char *)NULL);
					exit(-1);
				}
				else
				{	
					dup2(pipe_fds[1], 1);
					execlp("tee", "tee", "dirents",(char *)NULL);
					exit(-1);
				}
			}
		}
	}
    return 0;
}
