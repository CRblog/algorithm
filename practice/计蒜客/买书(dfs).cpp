#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int a[31];
bool istrue = false;
void dfs(int x,int sum,int count)
{
    if(x>n||sum>m||count>k)
    return;

    if(sum==m&&k==count)
    {
        istrue=true;
        return;
    }

    dfs(x+1,sum,count);
    dfs(x+1,sum+a[x],count+1);

}

int main()
{
    while(scanf("%d%d%d",&m,&n,&k)==3)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        istrue=false;
        dfs(0,0,0);
        if(istrue)
            cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;
    }
    return 0;
}
