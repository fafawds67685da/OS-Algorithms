#include<stdio.h>
int main()
{
	int n,m;
	printf("\t Enter the number of frames and size request string \n");
	scanf("%d",&n);
	scanf("%d",&m);

	int frames[n];
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
	}
	int x = 0;
	for(int i = n;i<m;i++)
	{
		int z = 0;
		for(int j =0;j<n;j++)
		{
			if(req[i]==frames[j])
			{
				z+=1;
			}
		}

		if(z==1)
		{
			z=0;
		}
		else
		{
			z=0;
			frames[x] = req[i];
			x = (x+1)%n;
			page_fault+=1;
		}
	}

	printf("\t Total number of page faults : %d \n",page_fault);
	return 0;
}	