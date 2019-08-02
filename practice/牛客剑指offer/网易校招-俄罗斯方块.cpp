#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,a;
    cin>>n>>m;
    vector<int>  arr(n,0);
    while(m--)
    {
        cin>>a;
        arr[a-1]++;
    }
    sort(arr.begin(),arr.end());
    cout<<arr[0]<<endl;
    return 0;
}
