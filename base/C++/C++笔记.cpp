//C++
//
//namespace 域
#include<stdio.h>
namespace my
{
	int a = 1;
}
namespace your
{
	int a = 2;
}

命名空间可以嵌套

//缺省参数
对参数指定一个默认值，没传参就用默认，传了参数就用传的
int main()
{
	printf("%d\n",my::a);
	printf("%d\n",your::a);
	return 0;
}
