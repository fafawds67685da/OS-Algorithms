#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int test, x;
	int fd[2];
	char re[100], wr[]="HEY THERE!";
	
	if((test=pipe(fd))==-1)
	{
		printf("\t Pipe system call failed \n");
		return 1;
	}

	x = fork();
	if(x>0)
	{
		close(fd[0]);
		printf("\t Parent process Writing \n");
		write(fd[1], wr, strlen(wr)+1);
		close(fd[1]);
		printf("\t Parent process done writing \n");
	}

	else if(x==0)
	{
		close(fd[1]);
		printf("\t Child process Reading \n");
		read(fd[0], re, strlen(wr)+1);
		close(fd[0]);
		printf("\t Child process done reading %s\n",re);
	}

	else
	{
		printf("\t Fork system call failed \n");
	}

	return 0;
}
