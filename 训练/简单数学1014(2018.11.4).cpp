//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
/*
    �ж��������Ƿ�Ϊ���������������Good Choice������Bad Choice
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
			return gcd(b,a%b);   //��Լ��
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
