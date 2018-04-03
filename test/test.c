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


int main(){

	int i = 0;

	signal(SIGALRM,myalarm);

	alarm(1);

	while(i<5){

		printf("ok\n");
		pause();
		alarm(1);
		i++;
	}



	

}