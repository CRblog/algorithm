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
	for(int i=start;i<n;i++)//��ʼλ��ѭ��
	{
	sum += a[i];
	mut *= a[i];
	//cout<<"1--"<<sum<<endl;
	//cout<<"1--"<<mut<<endl;
	if(sum>mut)            //���ڵĻ��ܺ;ͼ�1
	{
		ans++;
		dfs(i + 1);        //������������һ��Ԫ��
	}
	else if(a[i]==1)     //����һ���������Ӱ�죬ֻ��Ҫ�жϺ�����ܺ;Ϳ���
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
	while(i<n-1&&a[i]==a[i+1])  //ȥ�أ��ظ�������ͬһ�֣������������
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
		sort(a,a+n); //���������������ɸѡ��С�Ķ������㣬����Ĵ����ȻҲ������
		dfs(0);
		cout<<ans<<endl;
	}
    return 0;
}

