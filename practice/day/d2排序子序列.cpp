#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100001];
int main()
{
	int n;
	while(cin>>n)
	{
		int sum = 0;
		int equ = 0;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]<a[i+1])
			{
				while(a[i]<a[i+1])
				{
					i++;
				}
				sum++;
			}
			else if(a[i]>a[i+1])
			{
				while(a[i]>a[i+1])
				{
					i++;
				}
				sum++;
			}
			else
				equ++;
		}
		if(equ==n-1)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<sum<<endl;
		}
	}
	return 0;
}
