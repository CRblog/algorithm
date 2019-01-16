#include<bits/stdc++.h>
using namespace std;

//
////1.数组的逆序输出
//#define maxn 6
//int a[maxn];//整型变量数组
//int main()
//{
//	int x,n = 0;
//	while(scanf("%d",&x) == 1)
//		a[n++]=x;//{a[n]=x;  n=n+1;}
//	for(int i=n-1;i>=1;i--)
//		printf("%d",a[i]);
//	printf("%d\n",a[0]);
//	return 0;
//    复制数组：
//		//如果是两个整型   memcpy(b,a,sizeof(int) * k);
//						   memcpy(b,a,sizeof(double) * k);
//}


//2.开灯问题

//#define maxn 1010
//int a[maxn];
//int main()
//{
//	int n,k,first=1;
//	memset(a,0,sizeof(a));		//数组a全部初始化为0,,头文件为string.h
//	scanf("%d%d",&n,&k);
//	for(int i=0;i<=k;i++)
//		for(int j=0;j<=n;j++)
//			if(j%i==0) a[j] = !a[j];
//			
//	for(int i=1;i<=n;i++)
//		if(a[i])
//		{
//		if(first)
//		first = 0;
//		else
//		printf(" ");
//		printf("%d",i);}
//		printf("\n");
//		return 0;
//}

////3.生成元(Dight Generator ACM seoul 2005)
//#define maxn 1000005
//int ans[maxn];
////一次性枚举所有小于十万的数m
////标记 m加上m的各个数字之和得到的数有一个生成元是m
//int main() {
//	int T,n;
//	memset(ans,0,sizeof(ans));
//	for(int m=1;m<maxn;m++){//假设所求的生成元为 m
//		int x=m,y=m;
//		while(x>0)
//		{
//			y+=x%10;//原本是m，加上当前的余数
//			x/=10;
//		}
//		if(ans[y]==0||m<ans[y])
//			ans[y]=m;//如果m小于ans并且m+余数等于ans，那么m就是要找的这个值
//	}
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d",&n);
//		printf("%d\n",ans[n]);
//	}
//	return 0;
//}
