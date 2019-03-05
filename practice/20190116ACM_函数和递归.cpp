#include<bits/stdc++.h>
using namespace std;


//计算两点欧几里得距离的函数
//double dist(double x1,double y1,double x1,double y2)
//{
//	return sqrt((x1-x2)*(x1-x2)*(y1-y2)*(y1-y2));
//}
////算法竞赛中，要总是将让main返回0
//1.递归函数
//用递归法计算阶乘
int f(int n)
{
	return n==0?1:f(n-1)*n;
}
int main()
{
	printf("%d\n",f(3));
	return 0;
}
