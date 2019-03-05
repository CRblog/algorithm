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
        d[i]=dis[0][i];//保存到每个城市的距离
    for( int j = 1; j <= n; j++)
    {
        m=Max;
        for(int i = 1; i <= n ; i ++)//找草儿家到所有城市的最短的那个城市
        {
            if( m > d[i] && vis[i] == 0)//vis[i]==1时代表d[i]已经找过了
            {
                m = d[i];
                flag=i;
            }
        }
        vis[flag] = 1;//找过标记为1
        for(int i = 1; i <= n; i ++)
        {
            if( vis[i] == 0)//如果未更新过城市(p)，用距离最近的城市(k)加上(k)到(p)的距离，进行比较
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
        for(int i = 0; i <= 1000; i ++) //对dis数组进行初始化，
        {
            for( int j = 0; j <= 1000; j++)
                dis[i][j] = Max;//城市之间距离初始为Max
            dis[i][i] = 0;//城市到自身的距离为0
            d[i] = Max;//到每个城市的距离都为Max
        }
        memset(vis,0,sizeof(vis));//用来查看城市距离是否进行更新
        while( T --)//进行输入
        {
            cin >> a >> b >> c;
            n = max( n, (a,b) ); //求出最大城市数
            cout<<n<<endl;
            if(c < dis[a][b])//新输入的值若小于无穷大则进行更新
                dis[a][b] = dis[b][a] = c;
        }
        while(S --)
        {
            cin >> x;
            dis[0][x] = 0;//到隔壁城市的距离为0
        }
        djs();
        mm=Max;
        while(D --)
        {
            cin >> p;
            mm=min( mm, d[p]);//比较算出的距离哪个最小
        }
        cout << mm << endl;
    }
    return 0;
}
