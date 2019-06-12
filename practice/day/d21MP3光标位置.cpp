#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,len,count;
    string s;
    while(cin>>n>>s)
    {
        len = s.size();
        count = 0;
        for(int i=0;i<=n;++i)
        {
            if(s[i]=='U')
            {
                count+=1;
            }
            if(s[i]=='D')
            {
               count--;
			}
        }
        if(count<=4&&count>0)
        {
            for(int i=n-3;i<n;++i)
            {
                cout<<i<<" ";
            }
            cout<<n<<endl;
            cout<<n-count+1<<endl;
        }
        else if(count>4)
        {
            for(int i=n-count;i<n-count+3;++i)
            {
                cout<<i<<" ";
            }
            cout<<n-count+3<<endl;
            cout<<n-count<<endl;
        }
        else if(count<=0&&count>=-4)
        {
            for(int i=n+1;i<n+4;++i)
            {
                cout<<i<<" ";
            }
            cout<<n+4<<endl;
            cout<<n-count<<endl;
        }
        else
        {
            for(int i=n-count;i<n-count+3;++i)
            {
                cout<<i<<" ";
            }
            cout<<n-count+4<<endl;
            cout<<n-count<<endl;
        }
    }
    return 0;
}
