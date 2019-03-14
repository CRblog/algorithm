#include<iostream>
using namespace std;
//第一次AC代码，36ms
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

//第二次AC代码
//将两个不必要的循环合并了，后面的判断改成问号表达式了
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
//第三次代码，给输入加速优化（解除里面的C语言同步）
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
