#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a;
    while(cin>>a&&a!=0)
    {
        int count = 1;
        while(a>=4)
        {
            a = a/2;
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
