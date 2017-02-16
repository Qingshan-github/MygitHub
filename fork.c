#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char * argv[])
{
	pid_t pid = 0;
	int status = 0;
	/*fork chiled process*/
	pid = fork();
	
	if(pid == 0)
	{
		printf("this is chlied PID %d\n",getpid());
	}
	else if(pid > 0)
	{
		wait(&status);
		if(WEXITSTATUS(status))
		{

			printf("this is parent PID %d\n",getppid());
		}
	}
	else 
	{
		printf("fork process failed\n");
	}
	

	return 0;
}
