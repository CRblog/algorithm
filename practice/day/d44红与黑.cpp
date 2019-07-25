//#include<bits/stdc++.h>
//#include<vector>
//#include<iostream>
//using namespace std;
//void dfs(vector<vector<char> >& pass,int x,int y,int m,int n,int& sum)
//{
//   if(x<0||x>=m||y<0||y>=n||pass[x][y]=='1'||pass[x][y]=='#')
//       return;
//    sum++;
//	pass[x][y]='1';
//    dfs(pass,x,y-1,m,n,sum);
//    dfs(pass,x,y+1,m,n,sum);
//    dfs(pass,x+1,y,m,n,sum);
//    dfs(pass,x-1,y,m,n,sum);
//}
//int main()
//{
//	int m,n;
//    while(cin>>m>>n)
//    {
//        int a,b;
//        int sum = 0;
//        vector<vector<char> > pass(m,vector<char>(n,0));
//        for(size_t i=0;i<m;++i)
//        {
//            for(size_t j=0;j<n;++j)
//            {
//               cin>>pass[i][j];
//               if(pass[i][j]=='@')
//               {
//               	 a = i;
//               	 b = j;
//			   }
//            }
//        }
//        dfs(pass,a,b,m,n,sum);
//        cout<<sum<<endl;
//    }
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int m,n;
int sum=0;
int pass[20][20]={0};
void dfs(int x,int y)
{
   if(pass[x][y]==0||x<0||x>=m||y<0||y>=n)
   {
       return;
   }
    else
    {
        pass[x][y]=0;
        sum++;
        dfs(x,y-1);
        dfs(x,y+1);
        dfs(x+1,y);
        dfs(x-1,y);
    }
}
int main()
{
    while(cin>>m>>n)
    {
        getchar();
        char v;
        int a=0,b=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
               cin>>v;
                if(v=='@')
                {
                    pass[i][j]=1;
					a=i;
                    b=j;
                }
                if(v=='.')
                {
                	pass[i][j]=1;
				}
				if(v=='#')
				{
					pass[i][j]=0;
				}
            }
            getchar();
        }
        dfs(a,b);
        cout<<sum<<endl;
        sum=0;
        memset(pass,0,sizeof(pass));
    }
    return 0;
}
