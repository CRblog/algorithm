#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5];   //系数
int b[5];   //指数
int res = 0;
int mypow[153][5];
void MyPow()
{
    memset(mypow,1,sizeof(mypow));
    for(int i=1;i<=150;i++)
        for(int j=1;j<=4;j++)
            mypow[i][j] = i*mypow[i][j-1];
}
void dfs(int k,int val)
{
    if(k>n) return ;
    if(k==n)
    {
        if(val==0)
            res++;
        else
            return;
    }
	for(int i=1;i<=m;i++)
    {
        dfs(k+1,val+a[k]*mypow[i][b[k]]);
    }
}

int main()
{
    cin>>n>>m;
    MyPow();
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    dfs(0,0);
    cout<<res<<endl;
}
