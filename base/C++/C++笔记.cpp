//C++
//
//namespace ��
#include<stdio.h>
namespace my
{
	int a = 1;
}
namespace your
{
	int a = 2;
}

�����ռ����Ƕ��

//ȱʡ����
�Բ���ָ��һ��Ĭ��ֵ��û���ξ���Ĭ�ϣ����˲������ô���
int main()
{
	printf("%d\n",my::a);
	printf("%d\n",your::a);
	return 0;
}
