#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

char* fifo="fifo";

int main(){

	char buf[100];
	int fd;

	printf("전송할 메세지를 작성하세요 :");
	fgets(buf,sizeof(buf),stdin);
	buf[strlen(buf)-1] = 0;


	fd = open(fifo,O_WRONLY);

	write(fd,buf,MAX);



}