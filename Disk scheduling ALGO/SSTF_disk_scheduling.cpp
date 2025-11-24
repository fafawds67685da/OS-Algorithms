#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cout<<"\t Enter the length of the request string\n";
	cin>>n;
	int a[n];
	cout<<"\t Enter the request String\n";
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
	}
	int head;
	cout<<"\t Enter the head/ starting point \n";
	cin>>head;
	vector<int>large,small;
	for(int i =0;i<n;i++)
	{
		if(a[i]<head)
		{
			small.push_back(a[i]);
		}
		else
		{
			large.push_back(a[i]);
		}
	}
	
	sort(large.begin(), large.end());
	sort(small.begin(), small.end(), greater<int>());

	int move=0;
	move = abs(head-large[0]);
	for(int i =0;i<large.size()-1;i++)
	{
		move+=abs(large[i] - large[i+1]);
	}
	move+= abs(small[0]-large[large.size()-1]);
	for(int i =0;i<small.size()-1;i++)
	{
		move+=abs(small[i] - small[i+1]);
	}

	cout<<"\t Head movements are :"<<move<<"\n";

	return 0;
}
	
	