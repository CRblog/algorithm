#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
//��Ŀ������ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ
int drink(int money)
{
	int ans=money;
	int empty=money;
	while(empty>=2)
	{cout<<ans<<endl;cout<<"   "<<empty<<endl;
		ans+=empty/2;
		
		empty=empty/2+empty%2;
		
	}
	cout<<ans<<endl;
}

int main()
{
	drink(20);
	return 0;
}
