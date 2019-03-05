#include<iostream>
#include<cmath>
using namespace std;
int main()

{
	int x,y,s;
	while(cin>>x>>y)
	{

	if(x==0&&y==0)   return 0;
	 for(int i=x;i<=y;i++)
	 {
	 	s=i*i+i+41;
		for(int k=2;k<=s/2;k++)
		{
			if(s%k==0)
			{
			 cout<<"Sorry"<<endl;
             goto last;
             break;
			}
		}

	 }
	 cout<<"OK"<<endl;
     last : ;
	 }
	return 0;
}
