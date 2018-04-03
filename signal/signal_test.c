#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void action(int signum){
	printf("자는중입니다.\n");
	printf("지금 사용하는 시그널의 번호는 :%d\n",signum);

}

void action2(){
	printf("시그널입니다.\n");
}


int main() {


	static struct sigaction act;

	act.sa_handler=action;

	//sigaction(SIGINT,&act,NULL);
	signal(SIGUSR1,action2); 
	raise(SIGUSR1);


	
	printf("자는중입니다.\n");
	sleep(1);
	printf("자는중입니다.\n");
	sleep(1);
	printf("자는중입니다.\n");
	sleep(1);
	printf("자는중입니다.\n");
	sleep(1);
	printf("자는중입니다.\n");
	sleep(1);

	



}
