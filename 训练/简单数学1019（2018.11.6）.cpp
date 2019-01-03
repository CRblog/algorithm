//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
/*
最小公倍数*最大公约数=A*B
*/
int gcd(int a,int b)  //最小公约数
{
    return b==0?a:gcd(b,a%b);    //不断递归
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int n,m,a[1000],ans;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		}
		ans=0;
		if(m>1)  //如果只有一个元素，就输出这个元素，否则，两两求最小公倍数
		{
		
			for(int i=0;i<m-1;i++)
			{
				ans=lcm(a[i],a[i+1]);
				a[i+1]=ans;
			}
		
		}
		else
			ans=a[0];
		cout<<ans<<endl;
		
	}
	return 0;
}
