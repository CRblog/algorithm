//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
/*
��С������*���Լ��=A*B
*/
int gcd(int a,int b)  //��С��Լ��
{
    return b==0?a:gcd(b,a%b);    //���ϵݹ�
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
		if(m>1)  //���ֻ��һ��Ԫ�أ���������Ԫ�أ�������������С������
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
