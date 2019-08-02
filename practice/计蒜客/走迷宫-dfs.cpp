//计蒜客走迷宫--dfs
#include<bits/stdc++.h>

using namespace std;
int n,m;
int dx[8] = {1,0,-1,0};   //横向位移
int dy[8] = {0,1,0,-1};   //纵向位移
int ans = 0;              //保存结果
char a[11][11];           //迷宫大小
int vis[11][11];  //访问标记
void dfs(int x,int y)
{
	if(a[x][y]=='T')   //到终点了，路径+1
	{
		ans++;
		return;
	}
	vis[x][y] = 1;    //搜索过了，+1
	for(int i=0;i<4;i++)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];
		if((xx>=0&&xx<n)&&(yy>=0&&yy<m)&&a[xx][yy]!='#'&&vis[xx][yy]==0)
		//在迷宫范围内并且不是墙的点，没搜索过的点都搜索一遍
		{
			dfs(xx,yy);
		}
	}
	vis[x][y] = 0;
}
int main()
{
	cin>>n>>m;
	int x,y;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i][j]=='S')
			{
				dfs(i,j);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
