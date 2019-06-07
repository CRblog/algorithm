#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    int count,ans;
    while(cin>>n)
    {
        count = 0;
        if(n>500000||n<=0)
        {
            return -1;
        }
        else
        {
            for(int i=2;i<=n;++i)
            {
                ans = 0;
                for(int j=1;j<i;++j)
                {
                    if(i%j==0)
                    {
                        ans+=j;
                    }
                }
                //cout<<"i:"<<i<<"ans:"<<ans<<endl;
                if(ans==i)
                {
                    count++;
                }
            }

        }
        cout<<count<<endl;
    }
    return 0;
}
