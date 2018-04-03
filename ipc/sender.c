#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include "msgbuf.h"

void send(int msqid,char* request, int prio){

	int len;
	struct msgbuf rqst_buf;

	len = strlen(request);
	//if(len>MAXLEN){
		//perror("너무 긴 요청메세지입니다.");
	//	return -1;
	//}
	/*
	if(prio > MAXPRIO || prio < 0){
		perror("적절하지 않은 우선순위 입니다.");
		return -1;
	}
	*/
	rqst_buf.mtype = (long)prio;
	strcpy(rqst_buf.mtext,request);

	msgsnd(msqid,&rqst_buf,len, IPC_NOWAIT);
		
	
	
}


int main(int argc, char* argv[]){

	int id,prio, running=1 ;

	id = msgget(KEY,IPC_CREAT|0777);

	if(argc<3){
		perror("적절한 인풋이 아닙니다.");
		exit(1);
	}

	printf("키값으로 얻은 id '%d'\n",id );
	printf("입력한 request값 '%s'\n",argv[1]);
	printf("입력한 우선순위 '%s'\n",argv[2]);

	send(id, argv[1],atoi(argv[2]));
		

	return 0;
}