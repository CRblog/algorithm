#include<iostream>
using namespace std;

int main()
{
    int nArr[6][13] = {{0}};
    int nCost[6] = {0 , 2 , 5 , 3 , 10 , 4};  //花费
    int nVol[6]   = {0 , 1 , 3 , 2 , 6 , 2}; //物体体积
    int bagV = 12;

    for( int i = 1; i< sizeof(nCost)/sizeof(int); i++)
    {
        for( int j = 1; j<=bagV; j++)
        {
            if(j<nVol[i])
                nArr[i][j] = nArr[i-1][j];
            else
                nArr[i][j] = max(nArr[i-1][j] , nArr[i-1][j-nVol[i]] + nCost[i]);
            cout<<nArr[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<nArr[5][12]<<endl;

    return 0;
}


///*  /
//    杀怪经验值*杀怪数
//    sum+=杀怪数*经验值
//    做一个循环，sum+=a[i];   k-=b[i]
//    如果 sum>升级&&  k>=0;
//*/
////#include<bits/stdc++.h>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#define V 500
//using namespace std;
//int weight[20 + 1];
//int value[20 + 1];
//int f[V + 1];
//int max(int a, int b) {
//    return a > b ? a : b;
//}
//int main() {
//	
//    int n, m,s,y;
//    int max_a=0;
//    while(cin >>m >>s>> n >>y)
//	{
//    for (int i = 1; i <= n; i++) {
//        cin >> weight[i] >> value[i];
//        max_a=max(max_a,value[i]);
//    }
//    
//    for (int i = 1; i <= n; i++) {
//        for (int j = weight[i]; j <= m; j++) {
//            f[j] = max(f[j], f[j - weight[i]] + value[i]);
//        }
//    }
//    for(int i=0;i<n;i++)
//    {
//    	if(max_a*y<m){
//	
//			s=0;
//			f[m]=1;	}
//			else
//			continue;
//	}
//    cout<< s-f[m] << endl;
//	}
//	return 0;
//}
//
//struct   te{
//long long int a;
//long long int b;
//float w;
// 		   };
//int main()
//{
//long long int n,m,s,k,max_a;
//max_a=0;
//struct te t[103];
//struct te tem;
//	while(cin>>n>>m>>s>>k)
//	{
//		for(int i=0;i<s;i++)
//		{
//			cin>>t[i].a>>t[i].b;
//			max_a=max(max_a,t[i].a);
////			t[i].w=(float)t[i].a/t[i].b;
//		//	cout<<"                "<<t[i].w<<endl;
//		}
////	if(s>1)
////	{
////		for(int i=0;i<s;i++)
////		{
////			for(int j=0;j<s;j++)
////			{
////				if(t[j].w<t[j+1].w)  //
////				{
////					tem=t[j];
////					t[j]=t[j+1];
////					t[j+1]=tem;
////				}
////				
////			}
////		}
////	}
//////	cout<<"------"<<t[0].a<<endl;
////	for(int i=0;i<s;i++)
////	{
////		cout<<t[i].a<<"   "<<t[i].b<<endl;
////	}
//int sum=0;
//int cost=m;
////cout<<"       "<<max_a*k<<endl;
//		if(max_a*k>=m)
//		{
//			for(int j=0;j<s;j++)
//			{
//				for(int i=0;i<k;i++)
//				{
//					if(sum<n&&cost>0)
//					{
//						sum+=t[j].a;
//						cost-=t[j].b;
//						m-=t[j].b;
//					}
//						//cout<<"            "<<sum<<endl;
//						//cout<<cost<<endl;
//				}
//				
//			}
//			cout<<cost<<endl;
//		}
//	    else
//		cout<<"-1"<<endl;
//	}
//	return 0;
//}
