#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	
	int m,n;
	string table = "0123456789ABCDEF";
	while(cin>>m>>n)
	{
		string str = "";
		if(m==0)
		{
			cout<<"0"<<endl;
		}
		else if(m>0)
		{
			while(m)
			{
				str=table[m%n]+str;
				m/=n;
			}
			cout<<str<<endl;
		}
		else
		{
			m = abs(m);
		while(m)
			{
				str=table[m%n]+str;
				m/=n;
			}
			cout<<"-"<<str<<endl;
		}
			
	}
	return 0;
}
