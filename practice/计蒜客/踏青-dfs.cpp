//14 11
//...........
//.#.........
//.#......#..
//........#..
//...........
//#..........
//...........
//........#..
//........#..
//.#.........
//.#.........
//#...#......
//...........
//.....##.#..

#include<bits/stdc++.h>
using namespace std;
int count1 = 0;
int dx[8] = {1,0,-1,0};
int dy[8] = {0,1,0,-1};
int vis[104][104];
char M[104][104];
int n,m;  //ÐÐ£¬ÁÐ
int dfs(int x,int y)
{
    vis[x][y] = 1;
    for(int i=0;i<4;i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        cout<<xx<<"---"<<yy<<"---"<<vis[xx][yy]<<endl;
        if(xx>=0&&xx<=n&&yy>=0&&yy<=m&&vis[xx][yy]==0&&M[xx][yy]=='#')
        {
            dfs(xx,yy);
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        count1 = 0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>M[i][j];
            }
        }
         for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(vis[i][j]==0&&M[i][j]=='#')
                {
                	cout<<i<<"---"<<j<<endl;
                    count1++;
                    dfs(i,j);
                }
            }
        }
        cout<<count1<<endl;
    }
    return 0;
}
