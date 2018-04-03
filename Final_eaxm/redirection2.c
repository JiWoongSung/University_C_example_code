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
     
      close(p[0]);
    

      fd = open(file, O_RDWR);
      n=read(fd, buf, sizeof(buf));
      write(p[1],buf,n);
      exit(1);
   
   default: // 부모 
    
      //fd = open(file, O_RDWR);
     
      dup2(p[0],0);
      close(p[0]);
      close(p[1]);

      execvp(a[0], a);
      wait(NULL);
     
   }

}

int main(int argc, char* argv[]){

	char *one[2] = {"./test2", NULL}; 
	//char *two[2] = {argv[1], NULL};

	
  redirection(one, "number");
	
	exit(0);
	
}




