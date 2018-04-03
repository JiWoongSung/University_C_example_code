#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc ,char *argv[]){

	
	if(rename(argv[1],argv[2])==0){
		printf("rename완료\n");
	}

	else{
		printf("rename실패\n");
	}

}