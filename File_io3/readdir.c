#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc ,char *argv[]){

	DIR *ptr;
	struct dirent *dir;

	if((ptr=opendir(argv[1]))!=NULL){
		printf("폴더를 열었습니다.\n");
	}
	else{
		printf("폴더를 열지 못했습니다.\n");
	}
	

	while((dir=readdir(ptr))!=NULL){
		//printf("%s\n",dir->d_name );
	}


	rewinddir(ptr);

	 if(closedir(ptr)==0){
	 	printf("성공적으로 폴더를 닫았습니다.\n");
	 }

	 else{
	 	printf("폴더닫기를 실패했습니다.\n");
	 }
	

}