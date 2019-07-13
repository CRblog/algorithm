#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int mad(int a)
{
    if(a==1)
    {
        return 1;
    }
    if(a==2)
    {
    	return 2;
	}
    else
        return a*mad(a-1);
}
int main()
{
    int n;
    double p;
	long long a[21] = {0,0,1};
    for(int i=3;i<21;++i)
    {
    	a[i] = (i-1)*(a[i-1]+a[i-2]);
	}
    while(cin>>n)
    {
    	if(n>6)  //到6以上概率就相同了
    	{
    		cout<<"36.79%"<<endl;
		}
		else
        	cout<<setiosflags(ios::fixed)<<setprecision(2)<<(double)a[n]/mad(n)*100<<"%"<<endl;
    }
    return 0;
}
