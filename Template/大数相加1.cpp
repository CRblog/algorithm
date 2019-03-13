#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cstring>
using namespace std;
//大数相加思想
//将数字存在数组中，相同的位置相加(位数大的放在前面)，
//判断结果是否大于9，大于就证明有进位
//将加起来的数字除10，进位1
void bigIntergerAdd(string &num,string add)
{
	int goBit = 0;  //进位标志，初始化
	if(num.length()<add.length())
	{
		string tmp = num;
		num = add;
		add = tmp;
	}
	string tmp(num.length()-add.length(),'0');//长的和短的差几个0就补几个0
	add = tmp + add;     //往小的 前面（tmp在前） 补0
	//
	int len1 = num.length(),len2 = add.length();
	for(int i=len1-1;i>=0;--i)//从后往前
	{
		int tmp = ((num[i]-'0')+(add[i]-'0')+goBit);//数字相加再加进位
		num[i] = tmp%10 + '0';      //除以10的余数就是它当前位的值
		goBit = tmp/10;
	}
	if(goBit != 0) //如果最后一位还有进位，往前面添加一个1
		num.insert(0,string(1,(char)goBit+'0'));
		cout<<num<<endl;
}
int main()
{
	int t;
	string s1;
	string result;
	cin>>t;				//t组数据
	for(int i=1;i<=t;i++)
	{
		cin>>s1>>result;
		bigIntergerAdd(s1,result);
	}
	return 0;
}
