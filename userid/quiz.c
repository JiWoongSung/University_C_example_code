#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	char buf[1024];
	int fd1,fd2,n;	

	printf("real user id: %u \n", getuid());
	printf("effective user id: %d\n", geteuid());


	fd1=open(argv[1],O_RDWR);
	fd2=open(argv[2],O_APPEND|O_RDWR);

	n=read(fd1,buf,1024);
	write(fd2,buf,n);


	printf("fd?? %d, %d\n",fd1,fd2);	
	printf("%s\n",buf);




	return 0;


}
