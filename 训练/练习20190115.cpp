#include<bits/stdc++.h>
using namespace std;

//
////1.������������
//#define maxn 6
//int a[maxn];//���ͱ�������
//int main()
//{
//	int x,n = 0;
//	while(scanf("%d",&x) == 1)
//		a[n++]=x;//{a[n]=x;  n=n+1;}
//	for(int i=n-1;i>=1;i--)
//		printf("%d",a[i]);
//	printf("%d\n",a[0]);
//	return 0;
//    �������飺
//		//�������������   memcpy(b,a,sizeof(int) * k);
//						   memcpy(b,a,sizeof(double) * k);
//}


//2.��������

//#define maxn 1010
//int a[maxn];
//int main()
//{
//	int n,k,first=1;
//	memset(a,0,sizeof(a));		//����aȫ����ʼ��Ϊ0,,ͷ�ļ�Ϊstring.h
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

////3.����Ԫ(Dight Generator ACM seoul 2005)
//#define maxn 1000005
//int ans[maxn];
////һ����ö������С��ʮ�����m
////��� m����m�ĸ�������֮�͵õ�������һ������Ԫ��m
//int main() {
//	int T,n;
//	memset(ans,0,sizeof(ans));
//	for(int m=1;m<maxn;m++){//�������������ԪΪ m
//		int x=m,y=m;
//		while(x>0)
//		{
//			y+=x%10;//ԭ����m�����ϵ�ǰ������
//			x/=10;
//		}
//		if(ans[y]==0||m<ans[y])
//			ans[y]=m;//���mС��ans����m+��������ans����ôm����Ҫ�ҵ����ֵ
//	}
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d",&n);
//		printf("%d\n",ans[n]);
//	}
//	return 0;
//}
