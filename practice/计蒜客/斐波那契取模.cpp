#include<bits/stdc++.h>
using namespace std;



int main()
{
	int a[100003];
	int f[100003];
	a[1] = 1;
	a[2] = 1;
	int n;
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		a[i] =(a[i-1]+a[i-2])%1000000007;
		//f[n] =a[n]%1000000007;
	}
	
	cout<<a[n]<<endl;
	return 0;
}
