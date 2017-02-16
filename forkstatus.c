#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int a = 0;
int main(int argc ,char * argv[])
{
	pid_t pid = 0; 
	int i = 0;
	/*fork process*/
	int b = 0;
	pid = fork();
	
	for( i = 0; i < 40; i ++)
	{
		if(pid > 0)
		{
			++b;
			printf("parent %d\n",b);
		
		}
		if(pid == 0)
		{
			++b;
			printf("child %d\n",b);
		
		}
	}
	int status;
	if(pid > 0 )
	{
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("Normal Exit %d!\n",WEXITSTATUS(status));
		}
	}
	return 0;
}
