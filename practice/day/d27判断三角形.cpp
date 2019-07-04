#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {

        if(((a+b>c)&&(a+c>b)&&(b+c>a))&&((abs(a-b)<c)&&(abs(b-c)<a)&&(abs(a-c)<b)))
           cout<<"Yes"<<endl;
        else
           cout<<"No"<<endl;
    }
    return 0;
}
