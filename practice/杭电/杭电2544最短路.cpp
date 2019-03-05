#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int map[110][110];

int dis[10010]; //�������

int book[10010];    //�ж��Ƿ����

int n,m;

void dijkstra(int u)
{
	memset(dis,88,sizeof(dis));//�����о�������Ϊ���ֵ
	int start=u;
		book[start]=1;
	for(int i=1;i<=n;i++)
	{
		dis[i] = min(dis[i],map[start][i]);
		book[i]=0;
		//��������·֮��ľ���
	}
	dis[u]=0;

	for(int i=1;i<=n;i++)
	{
		int minn=9999999;
		for(int j=1;j<=n;j++)
			if(book[j]==0&&minn>dis[j])
			//ǰ����û�б������������Ҿ����С
			{
				minn=dis[j];    //����·��
				start=j;
			}

	book[start] = 1;    //�����������Ϊ1
	for(int j=1;j<=n;j++)
	{
		if(!book[j])
		dis[j] = min(dis[j],dis[start]+map[start][j]);
		//���µĵ�������dis
	}
		
	}
}
int main()
{
	while(cin>>n>>m)
	{
	memset(map,88,sizeof(map));//��ʼ��map
		if(n==0&&m==0)
		{
			exit(0);
		}
	
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;//�����о�����Ϣ����
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
