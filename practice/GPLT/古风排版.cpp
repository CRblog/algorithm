#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main()
{
	int n,num;
	char s[1003];
	char t[1000][1000];
	cin>>n;
	getchar();
	cin.getline(s,1003);
	int len = strlen(s);
	int m = len/n+1;
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(num<=len-1)
			{
				t[j][i] = s[num];
				num++;
			}
			else if(num>len-1&&num<n*(m-1))
			{
				t[j][i] =' ';
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

