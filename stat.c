#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	struct stat filestat;
	memset(&filestat,0,sizeof(filestat));

		int ret = stat("hello.c",&filestat);
		if(ret < 0)
		{
			perror("chek file fail!\n");
			exit(0);
		}
		int size = filestat.st_size;
			printf("file size %d\n",size);	
		char type;
		switch(filestat.st_mode & S_IFMT)
		{
			case S_IFLNK:
				type = 'L';
				break;
			case S_IFDIR:
				type = 'D';
				break;
			case S_IFIFO:
				type = 'P';	
				break;
			case S_IFREG:
				type = '-';
				break;
			case S_IFCHR:
				type = 'C';
				break;
			case S_IFBLK:
				type = 'B';
				break;
			case S_IFSOCK:
				type = 'S';
			default:
				type = '?';
				break;		
		}	

		printf("File Type :%c\n",type);
	
	return 0;
}
