#include<bits/stdc++.h>
using namespace std;
#define P 3.14
int main()
{
    double n,r;
    while(cin>>n>>r)
    {   bool acess = n < r * 2 * P;
        if(acess)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
