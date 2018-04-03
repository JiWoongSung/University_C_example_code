#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {


	int pid;
	int pid_n;
	int *status;



	pid= fork();

	if(pid==0){
		printf("자식프로세스 입니다. %d\n",getpid());
		
	}

	else{
		printf("부모 프로세스 입니다. %d\n",getpid());
		pid_n=waitpid(-1,status,0);

		printf("waitpid의 리턴 값입니다. %d\n",pid_n);
		printf("status값입니다. %d\n",&status );
	}




}