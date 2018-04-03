#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int myftw(char *pwd , int cwdlen){

	DIR* dirptr;
	DIR* dirptr2;

	struct dirent* dir;
	struct stat status;
	char buf[255]; // 이동할 경로
	char buf2[255]; // 그전 폴더로 돌아오기 위해 저장
	char pwdbuf[255]; //경로를 파싱하기위해
	char pwdbuf2[255]; //경로를 파싱하기위해
	int n = 0;



	if((dirptr = opendir(pwd)) == NULL) {  // dir유형에 대한 포인터 반환 , 현재 폴더를 가르키는 포인터
		perror("No such a directory\n");
		exit(-1);
	}

		

		while((dir = readdir(dirptr)) != NULL){ //struct dirent* 반환, 현재폴더를 읽는다. 

					if(dir->d_ino != 0){

						stat(dir->d_name,&status);

						if(S_ISREG(status.st_mode)){
						bzero(pwdbuf,255);
						bzero(pwdbuf2,255);
						getcwd(pwdbuf2,255);
					    strcat(pwdbuf,&pwdbuf2[cwdlen]);
						strcat(pwdbuf,"/");	
						strcat(pwdbuf,dir->d_name);

						printf("%-30s\t0%o\n",pwdbuf,status.st_mode&0777);

						
						}
						

						else if(S_ISDIR(status.st_mode)){
							bzero(pwdbuf,255);
							bzero(pwdbuf2,255);
							getcwd(pwdbuf2,255);
					 	    strcat(pwdbuf,&pwdbuf2[cwdlen]);
							strcat(pwdbuf,"/");	
							strcat(pwdbuf,dir->d_name);
							
							printf("%-30s*\t0%o\n",pwdbuf,status.st_mode&0777);
							
							n++; // .과 .. 지나고 출력 
							if(n>2){
							bzero(buf,255);
							bzero(buf2,255);
							getcwd(buf,255);
							getcwd(buf2,255);
							strcat(buf,"/");
							strcat(buf,dir->d_name);
							chdir(buf);

							printf("%s\n",buf );
							//printf("%s\n",buf2 );
							myftw(buf,cwdlen);


							chdir(buf2);
							}

						}

						else{
							printf("지정하지않은 파일 종류입니다.\n");
						}

					}
								
		}
	
		rewinddir(dirptr);
		closedir(dirptr);

	return 0;


}





int main(int argc, char* argv[]){
	
	char cwdlen[255];

	if(argc!=2){
		perror("No such a directory\n");
		exit(-1);
	}
		getcwd(cwdlen,255); //경로를 파싱하기위해


		myftw(argv[1],strlen(cwdlen));

	
	return 0;
}



