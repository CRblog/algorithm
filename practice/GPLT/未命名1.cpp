#include<bits/stdc++.h>
using namespace std;
int main()
{
  int h,m;
  scanf("%d:%d",&h,&m);
  if(h<=12)
  {
  	if(m<10&&h<10)
  	{
  		cout<<"Only 0"<<h<<":0"<<m<<".  Too early to Dang."<<endl;
	}
	else if(m<10&&h>=10)
	{
		cout<<"Only "<<h<<":0"<<m<<".  Too early to Dang."<<endl;
	}
	else if(m>=10&&h<10)
	{
		cout<<"Only 0"<<h<<":"<<m<<".  Too early to Dang."<<endl;
	}
	else
  	cout<<"Only "<<h<<":"<<m<<".  Too early to Dang."<<endl;
  }
  else if(h>12)
  {
     for(int i=0;i<h-12;i++)
	   {
	   	cout<<"Dang";
	   }
  	if(m==0)
  	{
	   
	   cout<<endl;
	}
	else
	{
		cout<<"Dang"<<endl;
	}
  }
  return 0;
}
