#include<bits/stdc++.h>
using namespace std;

struct node{
	int num[4]; //密码锁的4位状态
	int step;   //当前步数
};

char str[2][5]; //数字当作字符串输入
int vis[10][10][10][10];
int pwd[4];     //正确密码

//BFS
int bfs()
{
	node cur,nex;   //目前节点，下一个扩展节点
	for(int i=0;i<4;i++)
	{
		cur.num[i]=str[0][i]-'0';
		pwd[i]=str[1][i]-'0';//把字符串映射为数字
	}
	memset(vis,0,sizeof(vis));
	cur.step=0;
	queue<node> q;
	q.push(cur);
	int lock;   //判断是否为正确密码
	while(!q.empty())// 当前队列仍有元素可扩展
	{
		cur=q.front();  //得到对头状态
		q.pop();        //从队列中弹出队头状态
		lock=1;         //初始化为1
		for(int i=0;i<4;i++)
		{
			if(cur.num[i]!=pwd[i])
			{
				lock=0;
				break;
			}
		}
		if(lock)    //lock=1代表与密码相同
		{
			return cur.step;
		}
		for(int i=0;i<4;i++)
		{
			nex=cur;
			if(cur.num[i]==9)   nex.num[i]=1;   //9+1变1
			else    nex.num[i]=cur.num[i]+1;    //其他正常加1
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
			else nex.num[i]=cur.num[i]-1;   //正常-1
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
