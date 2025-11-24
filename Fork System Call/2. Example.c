#include<unistd.h>
#include<stdio.h>
int main()
{
	int n;
	printf("\t Enter the length of the array \n");
	scanf("%d",&n);
	int a[n];
	printf("\t Enter the elements of the arrays \n");
	for(int i =0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x = fork();
	if(x == 0)
	{
		int sum = 0;
		printf("\t Child Process \n");
		for(int i =0;i<n;i++)
		{
			if(i%2==0)
			{
				sum+=a[i];
			}
		}
		printf("\t Sum of even is :%d",sum);
				
	}

	else if(x>0)
	{
		printf("\t Parent Process \n");
		int sum = 0;
		for(int i =0;i<n;i++)
		{
			if(i%2!=0)
			{
				sum+=a[i];
			}
		}
		printf("\t Sum of odd is :%d",sum);
	}

	else
	{
		printf("\t Fork failed \n");
	}
	
	return 0;
} 