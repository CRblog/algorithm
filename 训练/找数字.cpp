#include<iostream>
using namespace std;
int main()
{
	int a[9]={1,2,3,4,5,5,4,3,2};
	for(int i=1;i<9;i++)
	{
			a[0]=a[0]^a[i];
	}
	cout<<a[0]<<endl;
	return 0;
}
