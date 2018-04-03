#include <stdio.h>
#include <signal.h>

int main(){


	sigset_t mask1;

	int n1=sigemptyset(&mask1);
	int n2=sigaddset(&mask1,SIGINT);
	//int n3=sigdelset(&mask1,SIGINT);
	//sigfillset(&mask1);
	int n4 =sigismember(&mask1,SIGINT);
	printf("n값은 뭘까여= %d %d %d\n",n1,n2,n4);


	if(sigismember(&mask1,SIGINT)){
		printf("SIGINT기능이 있습니다.\n");
	}
	else{
		printf("없지롱\n");
	}

}