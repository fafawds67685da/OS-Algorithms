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

	int visited[n];
	for(int i = 0; i < n; i++){
    	visited[i] = 0;
	}

	int v = n;
	int min = 9999,index;
	for(int i = 0 ;i<n;i++)
	{
		if(abs(req[i]-head)<min)
		{
			min = abs(req[i]-head);
			index = i;
		}
	}
	z = abs(head - req[index]);
	visited[index] = 1;
	v-=1;
	while(v>0)
	{	int index2;
		int min = 9999;
		for(int i =0;i<n;i++)
		{
			if(!(visited[i]))
			{
				
				if(abs(req[i]-req[index])<min)
				{
					min = abs(req[i]-req[index]);
					index2 = i;
				}
			}
		}	
		z+= abs(req[index] - req[index2]);
		visited[index2] = 1;
		index = index2;
		v-=1;
	}
					


	printf("\t Total head movements are :%d \n",z);
	return 0;
}
	
		