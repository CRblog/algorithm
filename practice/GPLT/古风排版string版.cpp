#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,num;
	char t[1003][1003];
	string s;
	cin>>n;
	getchar();
	getline(cin,s);
	int len = s.size();
	int m =len/n;
	if(len%n!=0)    m++;
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(num<len)
			{
			t[j][i]=s[num++];
			}
			else
			{
				t[j][i] = ' ';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<t[i][j];
		}
		cout<<endl;
	}
	return 0;
}
