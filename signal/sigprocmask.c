#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

int main(){


	sigset_t mask,mask2;

	sigfillset(&mask);
	//sigemptyset(&mask);

	//sigaddset(&mask,SIGINT);
	sigdelset(&mask,SIGINT);

	//sigemptyset(&mask2);
	sigprocmask(SIG_SETMASK,&mask,NULL);

	

	printf("자고있습니다.\n");
	sleep(1);
	printf("자고있습니다.\n");
	sleep(1);
	printf("자고있습니다.\n");
	sleep(1);
	printf("자고있습니다.\n");
	sleep(1);
	printf("자고있습니다.\n");
	sleep(1);
	


}