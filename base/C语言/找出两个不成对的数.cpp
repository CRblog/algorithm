#include<cstdio>
using namespace std;
//找知道两个只出现一次的数字
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
		//先将所有数字异或
	}
	for(i=0;i<32;i++)
	{
		if(1==((ret>>i)&1))
			{
				pos = i;
				break;
			}
	}//找到第一次出现一的位置并保存
	for(i=0;i<len;i++)
	{
		if(1==((arr[i]>>pos)&1))
		//分别异或回来，并分别输出原来的值
		{
			x ^= arr[i];
		}
		else
			y^=arr[i];
	}
	printf("这两个数分别为：%d 和 %d\n",x,y);
}
int main()
{
	int arr[] = {1,2,3,1,2,3,4,7};
	int sz = sizeof(arr)/sizeof(arr[0]);
	find_num(arr,sz);
	return 0;
}
