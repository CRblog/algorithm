#include<iostream>
using namespace std;
//��һ��AC���룬36ms
int reverse(int x)

{
	int sum=0;
	int l=0;
	int a=x;
	while(a)
	{
		l++;
		a/=10;
	}
	for(int i=0;i<l;i++)
	{
		sum=sum*10+x%10;
		x/=10;
	}
	
	return sum;
}

//�ڶ���AC����
//����������Ҫ��ѭ���ϲ��ˣ�������жϸĳ��ʺű��ʽ��
class Solution {
public:
    int reverse(int x) {
        long int sum=0;
	int a=x;
	while(a)
	{
		sum=sum*10+a%10;
		a/=10;
	}
	    return (sum<-pow(2, 31)||sum>pow(2, 31)-1)?:0(int)sum;
    }
};
//�����δ��룬����������Ż�����������C����ͬ����
static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int reverse(int x) {
        long int sum=0;
	int a=x;
	while(a)
	{
		sum=sum*10+a%10;
		a/=10;
	}
	    return (sum<-pow(2, 31)||sum>pow(2, 31)-1)?:0(int)sum;
    }
};

//
int main()
{
	cout<<reverse(1534236469)<<endl;
	return 0;
}
