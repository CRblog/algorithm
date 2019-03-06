#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,s;
	int a[100004];
	int b[100004];
	while(scanf("%d",&n)&&n!=0)
	{
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int k=-99999;
		for(int i=1;i<=n;i++)
		{
			s=-99999;
			for(int j=0;j<i;j++)
			  if(a[j]<a[i]&&s<b[j])
					s=b[j];
				b[i]=s+a[i];
				if(b[i]>k)
					k=b[i];
		}
		printf("%d\n",k);
	}
	return 0;
}
