#include<bits/stdc++.h>
using namespace std;


//��������ŷ����þ���ĺ���
//double dist(double x1,double y1,double x1,double y2)
//{
//	return sqrt((x1-x2)*(x1-x2)*(y1-y2)*(y1-y2));
//}
////�㷨�����У�Ҫ���ǽ���main����0
//1.�ݹ麯��
//�õݹ鷨����׳�
int f(int n)
{
	return n==0?1:f(n-1)*n;
}
int main()
{
	printf("%d\n",f(3));
	return 0;
}
