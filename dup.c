#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid; 
	int number = 2;
	int i = 0;
	int fd[2];
	pipe(fd);
	for(; i < number; i++)
	{
	
		pid = fork();
		if(pid == 0)
		{
			break;
		}
	}

	if(i ==number)
	{
		close(fd[1]);
		close(fd[0]);
		 for(i= 0 ; i < number; i++)
		 {
		 	wait(NULL);
		 }
	}
	else if(i == 0)
	{
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ps","ps","aux",NULL);
		exit(1);
	}

	else if(i == 1)
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("grep","grep","bash",NULL);
		exit(1);
	}
	return 0;
}
