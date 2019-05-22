#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
    long long sum = 0;
    while(cin>>n)
    {
        sum=0;
        vector<int> a;
        a.resize(3*n);
        for(int i=0;i<(3*n);i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        for(int i=n;i<=3*n-2;i+=2)
        {
            sum+= a[i];
        }
    cout<<sum<<endl;
    }
    return 0;
}
