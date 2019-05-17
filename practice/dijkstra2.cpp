#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

//����� 1������·��
//5    6
//1 2 5
//1 3 8
//2 3 1
//2 4 3
//4 5 7
//2 5 2
int map[110][110];  //�����map���飬�洢ͼ
//i �� j ��ȨֵΪ v
int dis[10010];     //dis���飬�洢����ֵ
//���������Ҳ�ǵ�ǰ�����ֵ
int book[10010];    //book[i]�����������û�б�����Դ��ȥ
//��������1Ϊ�У�0Ϊû�С������Ͳ����ظ�������
int n,m;
void dijkstra(int u)    //������������u��Դ����
{
	memset(dis,88,sizeof(dis));
	//��ʼ��·�����飬������ȫ����Ϊ���ֵ
	int start = u;      //�ȴ�Դ������
	book[start] = 1;    //Դ���Ѿ�������,���Ϊ 1
	for(int i=1;i<=n;i++)
	{
		dis[i] = min(dis[i],map[start][i]);
		//�Ƚ�dis[i]��ֵ��ԭ��map��ֵ
		//�ȸ���һ��
	}
	for(int i=1;i<=n-1;i++)
	{
		int minn=9999999;   //
		for(int j=1;j<=n;j++)
			if(book[j] == 0 && minn > dis[j])
			//���û��������
			{
				minn = dis[j];  //����ֵ�û���Сֵ
				start = j;      //�ҵ���Դ������ĵ㣬Ȼ��ѱ�ż�¼��������������
			}
		book[start] = 1;    //�������
		for(int j=1;j<=n;j++)
			dis[j] = min(dis[j],dis[start]+map[start][j]);
			//���µĵ�������dis
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
   dijkstra(1);     //��1ΪԴ��
   for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
}
