#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		printf("the invaild parameters \n");
		exit(0);
	}
	int ret = access(argv[1],F_OK);
	if(ret < 0)
	{
		ret = mkfifo(argv[1],0666);
			if(ret >0)
			{
				printf("create success!\n");
			}
			else if(ret < 0)
			{
				perror("mkfifo fail !\n");
				exit(1);
			}
	}

	int fd = open(argv[1],O_RDONLY | O_NONBLOCK);
	char buf[BUFSIZ];
	while(1)
	{
		memset(buf,0,BUFSIZ);
		int len = read(fd,buf,BUFSIZ);
		if(len <= 0)
		{
			printf("empty data!\n");
			sleep(2);	
			continue;
		}
		else
			write(STDOUT_FILENO,buf,len);
		
	}
	close(fd);
	return 0;
}
