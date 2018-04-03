#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 


int join(char *com1[], char *com2[])//pipe
{
  	int p[2], status;

  	switch(fork()){
  		case -1:
  			perror("dd");
  		case 0: // 자식 
  			break;
  		default: // 부모 
  			wait(&status);
  		return (status);
  	}

  	if(pipe(p) == -1)
		perror("dd");  

  	switch(fork()){
  		case -1:
  			perror("dd");
  		case 0: // 자식 , 쓰기 
  			dup2(p[1],1); // 1번 fd 에 p[1]을 복제한다. 
  			close(p[0]);
  			close(p[1]);
  			execvp(com1[0], com1);
  			perror("dd");

  		default: //부모 , 읽기  

  			dup2(p[0],0);
  			close(p[0]);
  			close(p[1]);
  			execvp(com2[0], com2);
  			perror("dd");
  	}
  	return (status);
}

int main(){

	char *one[4] = {"ls", "-l", "/usr/lib", NULL}; 
	char *two[3] = {"grep", "^d", NULL};
	int ret;
	ret = join (one, two);
	printf ("join returned %d\n", ret); 
	exit(0);
	
}




