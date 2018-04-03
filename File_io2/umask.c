#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){


	int n;
	n=umask(0444);

	printf("n= %d\n",n);


}
