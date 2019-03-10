#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(int a,int b){
	return a>b;
}//逆序排序
int main()
{
	
	int n,temp,count;
	int a[101];
	int c[2];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);//顺序排序
		count=0;
		for(int i=0;i<n;i++)//求最小奇数
		{   c[1]=0;//初始化为0
			if(a[i]%2==0)
				continue;
			else{
			c[1]=a[i];    //存一下最小的奇数
			if(n>1)
				a[i]=0;         //最小奇数赋0，排序后会在最后一位
				goto num;
				}
		}
	 num:
		sort(a,a+n,cmp);   //从大到小排序
		if(c[1]==0||a[0]==0)
			{
			cout<<"-1"<<endl;  //一直为0说明没有偶数//第一个为零说明不构成数
			}
		else
			{
			for(int i=0;i<n-1;i++)
			{
				cout<<a[i];//除了最后一个，排序输出
			}
			cout<<c[1]<<endl;//加上最后一个奇数
			}
	}
	return 0;
}
