#include<cstdio>
using namespace std;
//��֪������ֻ����һ�ε�����
void find_num(int arr[],int len)
{
	int i=0;
	int ret=0;
	int pos=0;
	int x=0;
	int y=0;
	for(i=0;i<32;i++)
	{
		ret ^= arr[i];
		//�Ƚ������������
	}
	for(i=0;i<32;i++)
	{
		if(1==((ret>>i)&1))
			{
				pos = i;
				break;
			}
	}//�ҵ���һ�γ���һ��λ�ò�����
	for(i=0;i<len;i++)
	{
		if(1==((arr[i]>>pos)&1))
		//�ֱ������������ֱ����ԭ����ֵ
		{
			x ^= arr[i];
		}
		else
			y^=arr[i];
	}
	printf("���������ֱ�Ϊ��%d �� %d\n",x,y);
}
int main()
{
	int arr[] = {1,2,3,1,2,3,4,7};
	int sz = sizeof(arr)/sizeof(arr[0]);
	find_num(arr,sz);
	return 0;
}
