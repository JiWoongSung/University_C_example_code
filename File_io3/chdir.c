#include <stdio.h>
#include <unistd.h>


int main(int argc ,char *argv[]){

	char buf[255];

	getcwd(buf,255);

	printf("%s\n",buf );

	if(chdir(argv[1])==0){
		printf("성공적으로 chmod하였습니다.\n");
	}
	getcwd(buf,255);
	printf("%s\n",buf );


}