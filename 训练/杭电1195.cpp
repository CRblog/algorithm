#include<bits/stdc++.h>
using namespace std;

struct node{
	int num[4]; //��������4λ״̬
	int step;   //��ǰ����
};

char str[2][5]; //���ֵ����ַ�������
int vis[10][10][10][10];
int pwd[4];     //��ȷ����

//BFS
int bfs()
{
	node cur,nex;   //Ŀǰ�ڵ㣬��һ����չ�ڵ�
	for(int i=0;i<4;i++)
	{
		cur.num[i]=str[0][i]-'0';
		pwd[i]=str[1][i]-'0';//���ַ���ӳ��Ϊ����
	}
	memset(vis,0,sizeof(vis));
	cur.step=0;
	queue<node> q;
	q.push(cur);
	int lock;   //�ж��Ƿ�Ϊ��ȷ����
	while(!q.empty())// ��ǰ��������Ԫ�ؿ���չ
	{
		cur=q.front();  //�õ���ͷ״̬
		q.pop();        //�Ӷ����е�����ͷ״̬
		lock=1;         //��ʼ��Ϊ1
		for(int i=0;i<4;i++)
		{
			if(cur.num[i]!=pwd[i])
			{
				lock=0;
				break;
			}
		}
		if(lock)    //lock=1������������ͬ
		{
			return cur.step;
		}
		for(int i=0;i<4;i++)
		{
			nex=cur;
			if(cur.num[i]==9)   nex.num[i]=1;   //9+1��1
			else    nex.num[i]=cur.num[i]+1;    //����������1
			if(!vis[nex.num[0]][nex.num[1]][nex.num[2]][nex.num[3]])
			{
				vis[nex.num[0]][nex.num[1]][nex.num[2]][nex.num[3]]=1;
				nex.step=cur.step+1;
				q.push(nex);
			}
		}
		for(int i=0;i<4;i++)
		{
			
			nex=cur;
			if(cur.num[i]==1)   nex.num[i]=9;   //1-1=9
			else nex.num[i]=cur.num[i]-1;   //����-1
			if(!vis[nex.num[0]][nex.num[1]][nex.num[2]][nex.num[3]])
			{
				vis[nex.num[0]][nex.num[1]][nex.num[2]][nex.num[3]]=1;
				nex.step=cur.step+1;
				q.push(nex);

			}
		}
		for(int i=0;i<3;i++)
		{
			nex=cur;
			nex.num[i]=cur.num[i+1];
			nex.num[i+1]=cur.num[i];
			if(!vis[nex.num[0]][nex.num[1]][nex.num[2]][nex.num[3]])
            {
                vis[nex.num[0]][nex.num[1]][nex.num[2]][nex.num[3]]=1;
                nex.step=cur.step+1;
                q.push(nex);
            }
		}
		
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str[0]>>str[1];
		cout<<bfs()<<endl;
	}
	return 0;
}
