#include<bits/stdc++.h>
using namespace std;

//暴搜-----打出方阵然后直接判断打印
    int a[1003][1003] = {0};
int main()
{
    int w,h;
	for(int i=0;i<1003;i+=4)
	{
		for(int j=0;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}
	for(int i=1;i<1003;i+=4)
	{
		for(int j=0;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}
	for(int i=0;i<1003;i+=4)
	{
		for(int j=1;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}
	for(int i=1;i<1003;i+=4)
	{
		for(int j=1;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}
	//
	for(int i=2;i<1003;i+=4)
	{
		for(int j=2;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}
	for(int i=3;i<1003;i+=4)
	{
		for(int j=3;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}
	for(int i=2;i<1003;i+=4)
	{
		for(int j=3;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}
	for(int i=3;i<1003;i+=4)
	{
		for(int j=2;j<1003;j+=4)
		{
			a[i][j] = 1;
		}
	}

    while(cin>>w>>h)
    {
        int count = 0;
         for(int i=0;i<h;i++)
         {
             for(int j=0;j<w;j++)
             {
                 if(a[i][j]==1)
                 {
                     count++;
                 }
             }
         }
     cout<<count<<endl;
   }
//         for(int i=0;i<h;i++)
//         {
//             for(int j=0;j<w;j++)
//             {
//                 cout<<a[i][j];
//             }
//             cout<<endl;
//         }
    return 0;
}
