#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h>

void redirection(char *a[],char *file){

   char buf[100];
   int p[2],pid, i;
   int n,fd;

   if(pipe(p)== -1)
      perror("pipe call");
   

   switch(fork()){
   
   case -1:
      perror("fork call");
      exit(1);
   

   case 0: // 자식 
      dup2(p[1],1);
      close(p[0]);
      close(p[1]);
      execvp(a[0], a);
      exit(1);
   
   default: // 부모 
    
      close(p[1]);
      fd = creat(file, 0644); // >
      //fd = open(file, O_CREAT|O_WRONlY|O_TRUNC, 0644);  
      //fd = open(file, O_RDWR|O_TRUNC , 0644); //  >!
      //fd = open(file, O_RDWR|O_CREAT|O_APPEND , 0644); // >>
                  
      while((n= read(p[0], buf, sizeof(buf)))!=0){
          write(fd,buf,n);
      }
      printf("redirection완료\n");
      wait(NULL);
     
   }

}

int main(int argc, char* argv[]){

	char *one[2] = {"ls", NULL}; 
	//char *two[2] = {argv[1], NULL};

	
  redirection(one, "a");
	
	exit(0);
	
}




