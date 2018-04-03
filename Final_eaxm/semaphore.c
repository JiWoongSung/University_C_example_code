#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semId;

struct sembuf P = {0,-1,SEM_UNDO}; 
struct sembuf V = {0,+1,SEM_UNDO};

/*
union semun2 {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *_buf;
}semarg;
*/
void work();

int main(){
	union semun semarg;

	semId=semget(0x1234,1,IPC_CREAT|0644); //세마포어 생성단계 

	semarg.val=1;
	semctl(semId,0,SETVAL,semarg); //초기화 과정 

	fork(); fork();
	work();
	

	semctl(semId,0,IPC_RMID,0);

	return 0;
}

void work(){

	semop(semId, &P, 1);
	printf("꺼내고%d\n",getpid() );
	printf("쓰고%d\n",getpid() );
	semop(semId, &V, 1);
}