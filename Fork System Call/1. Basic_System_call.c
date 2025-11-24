#include<unistd.h>
#include<stdio.h>
int main()
{
	int x = fork();
	if(x == 0)
	{
		printf("\t Child Process \n");
		printf("\t Process id : %d, Parent process id : %d, \n",getpid(), getppid());
	}

	else if(x>0)
	{
		printf("\t Parent Process \n");
		printf("\t Process id : %d, Parent process id : %d, \n",getpid(), getppid());
	}

	else
	{
		printf("\t Fork failed \n");
	}
	
	return 0;
} 