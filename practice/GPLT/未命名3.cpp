#include<bits/stdc++.h>
using namespace std;

int main()
{
	
int n;
cin>>n;
struct cr{
	char a;
	char b;
}ls[n][4];
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<4;j++)
  	{
  		scanf("%c-%c ",&ls[i][j].a,&ls[i][j].b);
	}
		
  }


  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<4;j++)
  	{
  		if(ls[i][j].b=='T')
  		{
  			cout<<ls[i][j].a-'A'+1;
		}
	}

  }cout<<endl;
  return 0;
}
