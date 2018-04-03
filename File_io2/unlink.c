#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc ,char *argv[]){

	
	if(unlink(argv[1])==0){
		printf("unlink성공\n");
	}

	else{
		printf("unlink실패\n");
	}

}