//算法白书练习

#include<bits/stdc++.h>
using namespace std;


//1.1   7744问题开方解法
//int main()
//{
//	for(int a=0;a<=9;a++)
//		for(int b=0;b<=9;b++)
//		{
//			int n=a*1100+b*11;
//			int m=floor(sqrt(n) + 0.5);//开方后精度可能会发生变化，加上0.5再向下取整
//			if(m*m==n)  printf("%d\n",n);
//		}
//		return 0;
//}
////1.2   7744问题非开方解法
//int main()
//{
//	for(int x=1;;x++)
//	{
//		int n=x*x;
//		if(n<1000) continue;
//		if(n>9999)  break;
//		int hi=n/100;
//		int lo=n%100;
//		if(hi/10==hi%10&&lo/10==lo%10)  printf("%d\n",n);
//	}
//	return 0;
//}
//2018.12.25  0:21 创建，修改
