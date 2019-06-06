#include<iostream>
using namespace std;

int main()
{
	int a;
	while(cin>>a)
	{
		int count = 0;
		while(a)
		{
			if(a%2!=0)
			{
				count++;
			}
			a/=2;
		}
		cout<<count<<endl;
	}
	return 0;
}
