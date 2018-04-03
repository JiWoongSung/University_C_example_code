#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include "msgbuf.h"

int receive(int id){

	int len;
	struct msgbuf rsq_buf;

	len=msgrcv(id,&rsq_buf,MAXLEN,(-1*MAXPRIO),MSG_NOERROR);
	
	if(len==-1){
		perror("읽기 에러입니다.");
		return -1;
	}
	else{
		//rsq_buf.mtext[len]='\0';
		printf("[s]-----> %s\n",rsq_buf.mtext);
		if(strcmp(rsq_buf.mtext, "end") == 0 )
			return 1;

		else{
		printf("읽어온 데이터는 : '%s'\n",rsq_buf.mtext);
		return 0;
		}
	}
}


int main(){

	int id,n;
	int size;
	char* request;
	id=msgget(KEY,IPC_CREAT|0777);


	while(1){

		n=receive(id);
		if(n==-1){
			perror("읽기 에러");
			exit(1);
		}

		else if (n == 1){
			break;
		}
	

	}


	msgctl(KEY,IPC_RMID,0);

}