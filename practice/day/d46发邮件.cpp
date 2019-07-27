
/*  2-->1*1*1
    3-->2*1*1
    4-->3*1*3
    5-->4*3*4
    */
#include<bits/stdc++.h>
using namespace std;
long int count(int n)
{
    if(n==0||n==1)
        return 0;
    if(n==2)
        return 1;
    else
        return (n-1)*(count(n-1)+count(n-2));
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<count(n)<<endl;
    }
    return 0;
}
