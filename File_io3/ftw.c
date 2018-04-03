#include <stdio.h>
#include <sys/stat.h>
#include <ftw.h>

int function(const char *name,const struct stat *ptr,int type){

	if(type == FTW_NS){
		return 0;
	}

	else if(type == FTW_F){
		printf("파일 입니다. %s\n", name);
	}

	else{
		printf("폴더 입니다. %s\n", name);
	}

	return 0;


}






int main(int argc ,char *argv[]){

	if(ftw(argv[1],function,1)==0){
		printf("성공적으로ftw함수실행\n");
	}

	return 0;
}