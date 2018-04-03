#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void a(){
	printf("안녕\n");
}

int main(void)
{
	int p;
	printf("현재 프로세스 아이디 입니다.%d\n",getpid());
	//p=fork();

	//if(p==0){
	//	printf("@자식 입니다.%d\n",getpid());
	//	printf("@부모는 %d\n",getppid() );
		execl("/bin/sh","aa",NULL);
	//	exit(0);
	//}

//	else{
//		printf("부모 입니다.%d\n",getpid());
//		printf("부모의 부모는 %d\n",getppid() );
//		wait(0);
//	}

	

}