#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define KEY 0100
#define MAXLEN 5
#define MAXPRIO 20

struct msgbuf
{
	long mtype;
	char mtext[MAXLEN+1];
	
};