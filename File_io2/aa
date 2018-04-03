#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc ,char *argv[]){

	printf("%s\n",argv[1] );

	if(access(argv[1],W_OK)==0){
		printf("쓰기권한 있습니다.\n");
	}
	else{
		printf("쓰기권한 없습니다.\n");
	}


	return 0;
}