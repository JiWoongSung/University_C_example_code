#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc ,char *argv[]){

	
	if(link(argv[1],argv[2])==0){
		printf("하드링크 연결\n");
	}
	else{
		printf("하드링크 연결실패\n");
	}

	
	if(symlink(argv[1],argv[3])==0){
		printf("소프트링크 연결\n");
	}
	else{
		printf("소프트링크 연결\n");
	}

}