#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int count = 0;
        int maxn = 0;
        while(n)
        {
            if(n%2==1)
            {
                count++;
                n/=2;
                maxn = max(count,maxn);
            }
            if(n%2==0)
            {
                count = 0;
                n/=2;
            }
        }
        cout<<maxn<<endl;
    }
    return 0;
}
