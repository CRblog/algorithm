#include<bits/stdc++.h>
using namespace std;
#define N 6
int main()
{
//			1
//		   1 1
//		  1 2 1
//		 1 3 3 1
	int a[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j||j==0)
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}

			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
