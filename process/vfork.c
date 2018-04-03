#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	int n= 0;

	printf("fork하기전 %d, n: %d \n", getpid(),n);

	pid_t pid = vfork();

	if(pid==0){
		printf("자식 프로세스 입니다. %d\n",getpid());
		n++;
		exit(1);
	}

	else{

		sleep(2);
		printf("부모 프로세스 입니다.%d\n",getpid());
		
	}

	printf("fork하기후 %d, n: %d \n", getpid(),n);

}