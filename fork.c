#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char * argv[])
{
	pid_t pid;

	/*fork chiled process*/
	pid = fork();
	
	if(pid == 0)
	{
		printf("this is chlied PID %d\n",getpid());
	}
	else if(pid > 0)
	{
		wait(NULL);
		printf("this is parent PID %d\n",getppid());
	}	
	else 
	{
		printf("fork process failed\n");
	}
	
	return 0;
}
