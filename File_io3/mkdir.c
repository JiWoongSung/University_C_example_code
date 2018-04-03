#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc ,char *argv[]){

	
	if(mkdir(argv[1],0666)==0){
		printf("폴더 생성완료\n");
	}

	else{
		printf("폴더 생성실패\n");
	}

}