#include<stdio.h>
int main()
{
	int n,m;
	printf("\t Enter the number of frames and size request string \n");
	scanf("%d",&n);
	scanf("%d",&m);

	int frames[n];
	int time[n];
	int req[m];

	printf("\t Enter the request String \n");
	for(int i =0;i<m;i++)
	{
		scanf("%d",&req[i]);
	}

	int page_fault = n;
	for(int i =0;i<n;i++)
	{
		frames[i] = req[i];
		time[i] = i;
	}
	for(int i = n;i<m;i++)
	{
		int z = 0,y;
		for(int j =0;j<n;j++)
		{
			if(req[i]==frames[j])
			{
				z+=1;
				y = j;
				break;
			}
		}

		if(z==1)
		{
			z=0;
			time[y]+= n;

		}
		else
		{
			z=0;
			int min = 9999, index;
			for(int j =0;j<n;j++)
			{
				if(time[j]<min)
				{
					min = time[j];
					index = j;
				}
			}
			frames[index] = req[i];
			time[index]+= n;	
			page_fault+=1;
		}
	}

	printf("\t Total number of page faults : %d \n",page_fault);
	return 0;
}	