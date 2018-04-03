#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc ,char *argv[]){

	printf("%s\n",argv[1] );

	if(chmod(argv[1],0666)==0){
		printf("변경완료했습니다.\n");
	}
	else{
		printf("변경 실패하였습니다..\n");
	}


	return 0;
}