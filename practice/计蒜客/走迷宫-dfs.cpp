//��������Թ�--dfs
#include<bits/stdc++.h>

using namespace std;
int n,m;
int dx[8] = {1,0,-1,0};   //����λ��
int dy[8] = {0,1,0,-1};   //����λ��
int ans = 0;              //������
char a[11][11];           //�Թ���С
int vis[11][11];  //���ʱ��
void dfs(int x,int y)
{
	if(a[x][y]=='T')   //���յ��ˣ�·��+1
	{
		ans++;
		return;
	}
	vis[x][y] = 1;    //�������ˣ�+1
	for(int i=0;i<4;i++)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];
		if((xx>=0&&xx<n)&&(yy>=0&&yy<m)&&a[xx][yy]!='#'&&vis[xx][yy]==0)
		//���Թ���Χ�ڲ��Ҳ���ǽ�ĵ㣬û�������ĵ㶼����һ��
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
