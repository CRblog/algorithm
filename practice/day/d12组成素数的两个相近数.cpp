#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool IsPrime(int n)
{
    for(int i=2;i<=sqrt(n*1.0);i++)
    {
        if(n % i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{

	
    int a;
    while(cin>>a)
    {
	    int minn=0,maxn=99999;
		int su1 = 0,su2 = 9999;
        for(int i=a/2;i>0;i--)
        {
            if(IsPrime(i))
            {
                su1 = i;
            }
            
			for(int j=a/2;j<a;j++)
        		{
            		if(IsPrime(j))
            		{
               			 su2 = j;
            		}
            		if(su1+su2==a)
            		{
						minn = max(su1,minn);
						maxn = min(su2,maxn);
					}
       			}
        }
	cout<<minn<<endl;
	cout<<maxn<<endl;
    }
	
    return 0;
}
