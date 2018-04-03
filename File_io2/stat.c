#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>


int main(int argc ,char *argv[]){

	struct stat info;
	struct passwd *my_passwd; 
	struct group  *my_group;
	
	if(stat(argv[1],&info)==0){
		printf("파일정보 받아오기 성공\n");
	}

	else{
		printf("파일정보 받기 실패\n");
	}

	if(S_ISREG(info.st_mode)){
		printf("일반파일입니다.\n");
		printf("%d\n", S_ISREG(info.st_mode));

		my_passwd = getpwuid(info.st_uid);
		my_group = getgrgid(info.st_gid);

		printf("%s\n",my_passwd->pw_name);
		printf("%s\n",my_group->gr_name);
	}
	else{
		printf("저장되지않은 파일입니다.\n");
	}


	

}