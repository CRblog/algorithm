#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1003];
int  n,ans,sum,mut;
void dfs(int start)
{
	//cout<<"1--"<<start<<endl;
	for(int i=start;i<n;i++)//开始位置循环
	{
	sum += a[i];
	mut *= a[i];
	//cout<<"1--"<<sum<<endl;
	//cout<<"1--"<<mut<<endl;
	if(sum>mut)            //大于的话总和就加1
	{
		ans++;
		dfs(i + 1);        //算完了跳到下一个元素
	}
	else if(a[i]==1)     //等于一的情况不会影响，只需要判断后面的总和就可以
	{
		dfs(i + 1);
	}
	else
	{
		sum -= a[i];
		mut /= a[i];
		break;
	}
	sum -= a[i];
	mut /= a[i];
	//cout<<"2--"<<sum<<endl;
	//cout<<"2--"<<mut<<endl;
	while(i<n-1&&a[i]==a[i+1])  //去重（重复号码算同一种，不计入次数）
	{
		i++;
	}
	}
}

int main()
{
    while(cin>>n)
    {
		ans = 0;
		sum = 0;
		mut = 1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n); //排序升序的作用是筛选，小的都不满足，后面的大的自然也不满足
		dfs(0);
		cout<<ans<<endl;
	}
    return 0;
}

