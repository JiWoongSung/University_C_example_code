#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void catchint(int signum){
		printf("SIGINT의 번호%d\n", signum);
		printf("다시 원래로 돌아갈게요\n");
}


int main(void){


	static struct sigaction act, oact;

	act.sa_handler = catchint;

	sigfillset(&(act.sa_mask));

	sigaction(SIGINT,&act,&oact); // SIGINT의 기능을 catchint로 바꿨다. 실행중에는 모든sigset이 블락된다 
	sigaction(SIGINT,&oact,NULL);

	printf("자는 중입니다.\n");
	sleep(1);
	printf("자는 중입니다.\n");
	sleep(1);
	printf("자는 중입니다.\n");
	sleep(1);
	printf("자는 중입니다.\n");
	sleep(1);

	exit(0);



}