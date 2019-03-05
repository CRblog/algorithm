#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long int f[1000001];
void fun()
{
	int i;
	f[0]=7;f[1]=11;
	f[0]%=3;f[1]%=3;
	for(i=2;i<=1000000;i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]%=3;
	}
}
int main()
{
	int n;
	int a,b;
	fun();
	while(cin>>n)
	{
		if(f[n]==0)
		{
			cout<<"yes"<<endl;
		}
		else
		cout<<"no"<<endl;
	}
	return 0;
}
