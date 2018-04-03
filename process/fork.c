#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	int n= 0;
	int p = 0;

	printf("fork하기전 %d, n: %d \n", getpid(),n);

	pid_t pid = fork();

	if(pid==0){
		printf("자식 프로세스 입니다. %d\n",getpid());
		exit(1);
	}

	else{

	
		printf("부모 프로세스 입니다.%d\n",getpid());
		p=wait(NULL);

		printf("기다린 자식프로세스 입니다. %d\n",pid );

	}

}
