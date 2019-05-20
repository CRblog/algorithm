#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,sum;
	
    while(cin>>n)
    {	sum=0;
	    int a[m];
	    m=3*n;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        sort(a,a+3*n);
        for(int i=3*n-2;i>=n;i-=2)
        {
            sum+= a[i];
        }
    cout<<sum<<endl;
    }
    return 0;
}
