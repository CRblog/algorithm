#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n;
	cin>>n;
        int flag1 = 1;
        int flag2 = 1;
        string str[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
			if(i>0)
			{
				if(str[i-1]>str[i])   //这地方字符串可以直接比较的（刚开始只比较了第一个字母）
            	{
              	  	flag1 = 0;
           		}
            	if(str[i-1].size()>str[i].size())
            	{
            	    flag2 = 0;
            	}
			}
        }
        //cout<<flag1<<flag2<<endl;
		if(flag1==0&&flag2==1)   //长度符合要求
        {
            cout<<"lengths"<<endl;
        }
		else if(flag1==1&&flag2==0)   //字典序符合要求
        {
            cout<<"lexicographically"<<endl;
        }
		else if(flag1&&flag2)    //都符合要求
        {
            cout<<"both"<<endl;
        }
        else
            cout<<"none"<<endl;
    return 0;
}
