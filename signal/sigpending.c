#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/types.h>

static void sig_quit(int);

int main(void) {

	sigset_t newmask, oldmask, pendmask;

	if (signal(SIGINT, sig_quit) == SIG_ERR) { 
		perror("can't catch SIGINT");
		exit(1);
	}
	/* block SIGQUIT and save currnet signal mask */ 
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);

	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) { 
		perror("SIG_BLOCK error");
		exit(1);
	} 
		sleep(5);
	if (sigpending(&pendmask) < 0) { 
		perror("sigpending error"); 
		exit(1);
	}
	if (sigismember(&pendmask, SIGINT)) 
		printf("\nSIGINT pending\n");
	/* reset signal mask which unblock SIGQUIT */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
		perror("SIG_SETMASK error");
		exit(1); 
	}	

	printf("SIGINT unblocked\n");


	/* SIGQUIT here will terminate with core file */ 
	sleep(5);
	exit(0);
}

static void sig_quit(int signo) {

		printf("caught SIGINT\n");
		if (signal(SIGINT, SIG_DFL) == SIG_ERR) { 
			perror("can't reset SIGQUIT");
			exit(1);
		}
		return; 
}