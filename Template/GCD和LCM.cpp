#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;
int gcd(int a,int b)//���Լ���Ż��㷨
{
	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)   //��С������

{
	return a/gcd(a,b)*b;
}


int main()
{
	cout<<gcd(5,7)<<endl;
	cout<<lcm(2,5)<<endl;
	return 0;
}
