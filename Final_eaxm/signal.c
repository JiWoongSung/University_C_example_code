#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

void func(int signum){
	printf("하이 내 signum은 %d 야\n",signum );
}


int main(){
	int n= 0;

	sigset_t mask,mask2;

	sigemptyset(&mask);

	sigaddset(&mask,SIGINT);
	//sigaddset(&mask,SIGINT);
	sigprocmask(SIG_BLOCK,&mask,NULL);



	
	/*
	if(sigismember(&mask2,SIGINT)){
		printf("하이\n");
	}
	else{
		printf("없다고;;\n");
	}

	*/
	signal(SIGINT,func);


	while(n!=5){

		sleep(3);
		printf("메롱 꺼봐라\n");
		n++;

			
	}


	

}
