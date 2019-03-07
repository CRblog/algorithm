#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
//题目：喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水
int drink(int money)
{
	int ans=money;
	int empty=money;
	while(empty>=2)
	{cout<<ans<<endl;cout<<"   "<<empty<<endl;
		ans+=empty/2;
		
		empty=empty/2+empty%2;
		
	}
	cout<<ans<<endl;
}

int main()
{
	drink(20);
	return 0;
}
