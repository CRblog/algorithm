#include<bits/stdc++.h>
using namespace std;


int main()
{

int n,sum;
double w,ans;
cin>>n;
struct ll{
	double a;
	double b;
}ll[n];
cin>>sum;

for(int i=0;i<n;i++)
{
	cin>>ll[i].a;
}
for(int i=0;i<n;i++)
{
	cin>>ll[i].b;
}
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		if(ll[j+1].b/ll[j+1].a>ll[j].b/ll[j].a)
		{
			int tmp = ll[j].a;
			ll[j].a = ll[j+1].a;
			ll[j+1].a=tmp;
			int tp = ll[j].b;
			ll[j].b = ll[j+1].b;
			ll[j+1].b=tp;
		}
	}
}
//cout<<ll[1].a<<ll[1].b<<endl;
ans = 0;
for(int i=0;i<n;i++)
{
	if(sum>=ll[i].a)
	{
		sum-=ll[i].a;
		ans+=ll[i].b;
		//cout<<ans<<endl;
	}
	else if(sum<ll[i].a&&sum>0)
	{
		ans+=ll[i].b*(ll[i].a-sum)/ll[i].a;
		sum-=sum;
		//cout<<ll[i].b<<"  "<<ll[i].a<<"  "<<ll[i].a-sum<<endl;
		
	}
	else
	cout<<fixed<<setprecision(2)<<ans<<endl;
}

return 0;
}
