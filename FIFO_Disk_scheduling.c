#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("\t Enter the length of the request string \n");
	scanf("%d",&n);
	int req[n];
	printf("\t Enter the request string \n");
	for(int i =0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	int head;
	printf("\t Enter the head/ Starting point/ cylinder of the disk \n");
	scanf("%d",&head);
	int z = 0;
	z = abs(head-req[0]);
	for(int i =0;i<n-1;i++)
	{
		z+= abs(req[i] - req[i+1]);
	}

	printf("\t Total head movements are :%d \n",z);
	return 0;
}
	
		