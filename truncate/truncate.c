#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int n;

	n=truncate(argv[1],10);
	
	printf("return value : %d \n",n);

	return 0;


}
