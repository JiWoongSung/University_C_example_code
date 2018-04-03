#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

char* p = "안뇽" ;
char* p2 = "안뇽2" ;

int main(){

	int fd[2],pid;
	char buf[100];

	if (pipe(fd) < 0) {
	perror("pipe call");
	exit(1); 
	}

	if ((pid = fork()) < 0) { perror("fork call"); exit(2);
	}

	while(1){
		
	if(pid==0){
		dup2(p[1],1);
		close(fd[0]);
		close(fd[1]);


	}


	else{
		dup2(p[0],0);
		close(fd[1]);
		close(fd[0]);

		

		
		wait(NULL);
	}

	exit(0);

	}
}