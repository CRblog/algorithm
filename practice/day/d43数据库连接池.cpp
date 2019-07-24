#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while(cin>>n)
    {
        char name;
        string op;
        int maxn = 0;
        int count = 0;
        for(int i=0;i<n;++i)
        {
            cin>>name>>op;
            if(op=="connect")
            {
                ++count;
                maxn = max(maxn,count);
            }
            else
                --count;
        }
        cout<<maxn<<endl;
    }
    return 0;
}
