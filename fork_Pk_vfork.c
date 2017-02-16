#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

	int i = 0 ;
int main(int argc, char * argv[])
{
	pid_t pid ;
	 
	pid = vfork();
	if(pid > 0 )
	{
		for(; i < 5; i++)
		{}
	}

	else if(pid == 0)
	{
		printf("i = %d\n",i);
		//execlp("echo","echo","hello,world\n",NULL);
		exit(0);
	}		
	
	return 0;
}
