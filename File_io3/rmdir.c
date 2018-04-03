#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc ,char *argv[]){

	
	if(rmdir(argv[1])==0){
		printf("폴더 삭제완료\n");
	}

	else{
		printf("폴더 삭제실패\n");
	}

}