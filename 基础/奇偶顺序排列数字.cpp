#include<iostream>
using namespace std;

int exg(int a[],int length)
{
	for(int i=0;i<length;i++)
	{
		if(a[i]%2 != 0)
			cout<<a[i];
	}
	for(int j=0;j<length;j++)
	{
		if(a[j]%2==0)
			cout<<a[j];
	}
	cout<<endl;
	
}

int main()
{
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	int length=sizeof(arr)/sizeof(arr[0]);
	exg(arr,length);
	return 0;
}
