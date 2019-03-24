#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	int n,len;
	char c;
    string a;
	cin>>n;
	cin>>c;
	cin.get();
	getline(cin,a);
	len = a.length();
	if(len<n)
	{
		for(int i=0;i<n-len;i++)
		{
			cout<<c;
		}
	}
	
	else if(len>n)
	{
  		for(int i=len-n;i<len;i++)
		{
			cout<<a[i];
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<c;
		}
	}
  return 0;
}
