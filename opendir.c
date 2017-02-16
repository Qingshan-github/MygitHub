#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int get_File_Number(char * r)
{
	DIR * dir = NULL;
	dir = opendir(r);
	if(dir == NULL)
	{
		printf("No File and directories!\n");
		exit(1);
	}
	struct dirent *root;
	char path[1024] = {0};
	
	int Number = 0;
	while((root = readdir(dir)) != NULL){
		memset(path,0,1024);
 		printf("%s\n",root->d_name); 
		 if(strcmp(root->d_name,".") == 0 ||
			strcmp(root->d_name,"..") == 0) continue;
		 else if (root->d_type == DT_DIR)
		 {				
			 sprintf(path,"%s/%s",r,root->d_name);
				Number += get_File_Number(path); 
		
		 }
		 else if(root->d_type == DT_REG)
		 {
			Number ++; 
		 }
	}
	closedir(dir);
	return Number;
}

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		printf("./opendir [dirent]\n");
		exit(0);
	}
	int count = get_File_Number(argv[1]);
	printf("文件数量：%d\n",count);
	return 0;
}
