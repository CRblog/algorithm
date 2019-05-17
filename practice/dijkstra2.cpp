#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

//输出到 1点的最短路径
//5    6
//1 2 5
//1 3 8
//2 3 1
//2 4 3
//4 5 7
//2 5 2
int map[110][110];  //这就是map数组，存储图
//i 到 j 的权值为 v
int dis[10010];     //dis数组，存储估计值
//最终输出的也是当前数组的值
int book[10010];    //book[i]代表这个点有没有被当做源点去
//搜索过，1为有，0为没有。这样就不会重复搜索了
int n,m;
void dijkstra(int u)    //主函数，参数u是源点编号
{
	memset(dis,88,sizeof(dis));
	//初始化路径数组，将距离全部设为最大值
	int start = u;      //先从源点搜索
	book[start] = 1;    //源点已经搜索过,标记为 1
	for(int i=1;i<=n;i++)
	{
		dis[i] = min(dis[i],map[start][i]);
		//比较dis[i]的值和原本map的值
		//先更新一遍
	}
	for(int i=1;i<=n-1;i++)
	{
		int minn=9999999;   //
		for(int j=1;j<=n;j++)
			if(book[j] == 0 && minn > dis[j])
			//如果没有搜索过
			{
				minn = dis[j];  //将大值置换成小值
				start = j;      //找到离源点最近的点，然后把编号记录下来，用于搜索
			}
		book[start] = 1;    //标记搜索
		for(int j=1;j<=n;j++)
			dis[j] = min(dis[j],dis[start]+map[start][j]);
			//以新的点来更新dis
	}
}
int main()
{
	cin>>n>>m;
	memset(map,88,sizeof(map));
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=c;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)
				map[i][j]=0;
   dijkstra(1);     //以1为源点
   for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
}
