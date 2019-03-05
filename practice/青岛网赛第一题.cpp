#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,n,m,k;
	int min,max;
       while(cin>>t){
		for(int i=0;i<t;i++)	{
			cin>>n>>m;
			if(n==m)    {
			cout<<n<<" "<<m<<endl;}
			if(n>m){
			   max=m;
			   min=floor(n/(n-m+1));
			   cout<<max<<" "<<min<<endl;}	}	}
	return 0;}


