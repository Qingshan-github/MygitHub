#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc ,char * argv[])
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

	int fd = open(argv[1],O_WRONLY);
	char buf[BUFSIZ] = {0};
	int i = 0 ;
		printf("1");
	while(1)
	{
		memset(buf,0,BUFSIZ);
		int len = read(STDIN_FILENO,buf,BUFSIZ);
		write(fd,buf,len);
		fflush(stdin);
	}
	close(fd);
	return 0;
}
