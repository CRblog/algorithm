//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
/*
    判断两个数是否互为质数，是质数输出Good Choice，否则Bad Choice
*/
	bool gcd(int a,int b)
	{
		if(a%b==0)
		{
			if(b==1)
				return true;
			else
				return false;
		}
		else
			return gcd(b,a%b);   //公约数
	}
int main()
{
	int a,b;
	while(cin>>b>>a)
	{
		cout<<setw(10)<<fixed<<b<<setw(10)<<fixed<<a<<"    ";
		if(gcd(a,b))
			cout<<"Good Choice"<<endl;
		else
			cout<<"Bad Choice"<<endl;
			cout<<endl;
	}
	return 0;
}
