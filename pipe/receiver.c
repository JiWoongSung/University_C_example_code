#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX 100

char* fifo="fifo";

int main(){


	char buf[MAX];
	int fd;


	mkfifo(fifo,0666);

	fd = open(fifo,O_RDWR);


	for(;;){
	if(read(fd,buf,MAX)<0){
		perror("잘못 읽어 왔습니다.");
	}

	printf("읽어온 내용은: %s\n",buf);
	
	}


}