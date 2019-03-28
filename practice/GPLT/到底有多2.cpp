#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int  n;
	cin>>n;
	double fu = 1;
	double db = 1;
	double count1 = 0;
	double count2 = 0;
	if(n<0)
	{
		fu=1.5;
	}
	if(n%2==0)
	{
	   	db=2;
	}
		while(n)
		{
		count1++;
		if(-n%10==2||n%10==2)
		{
			count2++;
		}
		n=n/10;
		}
	count2 = count2*100;
	double s =count2/count1*fu*db;
	printf("%.2f\%\n",s);
	return 0;
}
