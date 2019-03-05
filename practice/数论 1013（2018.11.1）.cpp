//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    char str[1000];
    int sum,i;
    while(cin>>str)
    {
        sum=0;
       if(str[0]=='0')
       {
           break;
       }
       for(i=0;i<strlen(str);i++)
       {
            sum+=str[i]-'0';//第一次的和相加
       }
        while(sum>=10)
        {
            i=0;
            while(sum>0)
            {
                i+=sum%10;
                sum/=10;
            }
            sum=i;//再赋值，判断是否重新开始
        }
        cout<<sum<<endl;
    }
    return 0;
}
