#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int map[110][110];

int dis[10010]; //储存距离

int book[10010];    //判断是否检查过

int n,m;

void dijkstra(int u)
{
	memset(dis,88,sizeof(dis));//将所有距离设置为最大值
	int start=u;
		book[start]=1;
	for(int i=1;i<=n;i++)
	{
		dis[i] = min(dis[i],map[start][i]);
		book[i]=0;
		//更新两条路之间的距离
	}
	dis[u]=0;

	for(int i=1;i<=n;i++)
	{
		int minn=9999999;
		for(int j=1;j<=n;j++)
			if(book[j]==0&&minn>dis[j])
			//前提是没有被搜索过，并且距离更小
			{
				minn=dis[j];    //更新路径
				start=j;
			}

	book[start] = 1;    //搜索过，标记为1
	for(int j=1;j<=n;j++)
	{
		if(!book[j])
		dis[j] = min(dis[j],dis[start]+map[start][j]);
		//以新的点来更新dis
	}
		
	}
}
int main()
{
	while(cin>>n>>m)
	{
	memset(map,88,sizeof(map));//初始化map
		if(n==0&&m==0)
		{
			exit(0);
		}
	
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;//将已有距离信息更新
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)
				map[i][j]=map[j][i]=0;
 		dijkstra(1);
		cout<<dis[n]<<endl;
	}
	return 0;
}
