#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cstring>
using namespace std;
//�������˼��
//�����ִ��������У���ͬ��λ�����(λ����ķ���ǰ��)��
//�жϽ���Ƿ����9�����ھ�֤���н�λ
//�������������ֳ�10����λ1
void bigIntergerAdd(string &num,string add)
{
	int goBit = 0;  //��λ��־����ʼ��
	if(num.length()<add.length())
	{
		string tmp = num;
		num = add;
		add = tmp;
	}
	string tmp(num.length()-add.length(),'0');//���ĺͶ̵Ĳ��0�Ͳ�����0
	add = tmp + add;     //��С�� ǰ�棨tmp��ǰ�� ��0
	//
	int len1 = num.length(),len2 = add.length();
	for(int i=len1-1;i>=0;--i)//�Ӻ���ǰ
	{
		int tmp = ((num[i]-'0')+(add[i]-'0')+goBit);//��������ټӽ�λ
		num[i] = tmp%10 + '0';      //����10��������������ǰλ��ֵ
		goBit = tmp/10;
	}
	if(goBit != 0) //������һλ���н�λ����ǰ�����һ��1
		num.insert(0,string(1,(char)goBit+'0'));
		cout<<num<<endl;
}
int main()
{
	int t;
	string s1;
	string result;
	cin>>t;				//t������
	for(int i=1;i<=t;i++)
	{
		cin>>s1>>result;
		bigIntergerAdd(s1,result);
	}
	return 0;
}
