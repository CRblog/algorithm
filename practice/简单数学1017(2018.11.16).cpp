#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
int t,m,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{	
		int ca=1;
		while(cin>>n>>m&&(n||m))
		{
			int count = 0 ;
			for(int k=1;k<n;k++)
			{
				for(int j=k+1;j<n;j++)
				{
					if((j*j+k*k+m)%(k*j)==0)
					{
						count++;
					}
				}
			}
			cout<<"Case "<<ca<<": "<<count<<endl;
			ca++;
		}
		if(i<t-1)
		{
			cout<<endl;
		}
	}
	return 0;
}
