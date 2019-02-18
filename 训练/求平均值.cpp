#include<iostream>
using namespace std;
int main()
{
	int a,b,sum;
	cin>>a>>b;
	if(a>=b)
	{
		sum=b+(a-b)/2;
	}
	else
		sum=a+(b-a)/2;
	cout<<sum<<endl;
}
