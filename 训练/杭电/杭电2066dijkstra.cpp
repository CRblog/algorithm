#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
const int Max = 9999999;
int dis[1002][1002],vis[1002],d[1002],n,m,flag;
void djs()
{
    for( int i = 0; i <= n; i ++)
        d[i]=dis[0][i];//���浽ÿ�����еľ���
    for( int j = 1; j <= n; j++)
    {
        m=Max;
        for(int i = 1; i <= n ; i ++)//�Ҳݶ��ҵ����г��е���̵��Ǹ�����
        {
            if( m > d[i] && vis[i] == 0)//vis[i]==1ʱ����d[i]�Ѿ��ҹ���
            {
                m = d[i];
                flag=i;
            }
        }
        vis[flag] = 1;//�ҹ����Ϊ1
        for(int i = 1; i <= n; i ++)
        {
            if( vis[i] == 0)//���δ���¹�����(p)���þ�������ĳ���(k)����(k)��(p)�ľ��룬���бȽ�
                d[i] = min( d[i], d[flag]+dis[flag][i]);
        }
    }
}
int main()
{
    int T,S,D,a,b,c,p,x,mm;
    while(cin >> T >> S >> D)
    {
        n=0;
        for(int i = 0; i <= 1000; i ++) //��dis������г�ʼ����
        {
            for( int j = 0; j <= 1000; j++)
                dis[i][j] = Max;//����֮������ʼΪMax
            dis[i][i] = 0;//���е�����ľ���Ϊ0
            d[i] = Max;//��ÿ�����еľ��붼ΪMax
        }
        memset(vis,0,sizeof(vis));//�����鿴���о����Ƿ���и���
        while( T --)//��������
        {
            cin >> a >> b >> c;
            n = max( n, (a,b) ); //�����������
            cout<<n<<endl;
            if(c < dis[a][b])//�������ֵ��С�����������и���
                dis[a][b] = dis[b][a] = c;
        }
        while(S --)
        {
            cin >> x;
            dis[0][x] = 0;//�����ڳ��еľ���Ϊ0
        }
        djs();
        mm=Max;
        while(D --)
        {
            cin >> p;
            mm=min( mm, d[p]);//�Ƚ�����ľ����ĸ���С
        }
        cout << mm << endl;
    }
    return 0;
}
