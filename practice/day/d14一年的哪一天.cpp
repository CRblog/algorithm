#include<iostream>
using namespace std;

bool runyear(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))
        return 1;
    else
        return 0;
}
int main()
{
    int y,m,d;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(cin>>y>>m>>d)
    {
        int ans = 0;
        if(m>12||d>31)
            cout<<"-1"<<endl;
        if(runyear(y))
        {
            ans+=1;
        }
        for(int i=0;i<m-1;i++)
        {
            ans+=month[i];
            //cout<<i<<"---"<<month[i]<<"--"<<ans<<endl;
        }
        ans+=d;
        //cout<<month[1]<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

