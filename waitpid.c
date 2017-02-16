#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	pid_t pid = 0;

	pid = fork();
	int stat;
	if(pid > 0)
	{	
		waitpid(pid,&stat,0);
		if(WIFEXITED(stat))
		printf(" status Number :%d\n",WEXITSTATUS(stat));
	}
	if(pid == 0 )
	{
		int i = 0;
		while(i<1000)
		{
		
		i++;
		}
		exit(EXIT_SUCCESS);
	}
	return 0;
}
