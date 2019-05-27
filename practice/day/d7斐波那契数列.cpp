#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int flag = 0;
	int a[1000003];
	int fib[1000003];
	fib[0] = 0;
	fib[1] = 1;
	cin>>n;
	a[0] =abs(n-fib[0]);
	a[1] =abs(n-fib[1]);
		for(int i=2;flag!=1;i++)
		{
			fib[i] = fib[i-1]+fib[i-2];
			a[i]= abs(n-fib[i]);
			//cout<<a[i]<<endl;
//			if(i>5)
//			{
//				flag=1;
//			}
			if(a[i]>a[i-1])
			{
				flag =1;
				cout<<min(a[i],a[i-1])<<endl;
			}
		}
	return 0;
}
