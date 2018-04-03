#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>

void myalarm(){

	printf("알람이 울렸습니다.\n");

}

void newalarm(int secs){

	int n;

	n=fork();

	if(n==0){

		sleep(1);
		//kill(n,SIGALRM);
		raise(SIGALRM);
		exit(1);
	}

	

}


int main(){

	
	int i = 0;

	signal(SIGALRM,myalarm);

	newalarm(1);


	
	while(i<5){

		printf("ok\n");
		pause();
		newalarm(1);
		i++;
	}
	
	

}