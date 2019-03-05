#include<cstdio>
#include<iostream>
#define ROW 3
#define COL 3
using namespace std;
int Findnum(int arr[ROW][COL], int row, int col, int key)
{
	int left = 0;
	int right = col-1;
	while((left >= 0) && (right <col)&&(left<row))
	{
		if(arr[left][right] < key)
		{
			left++;
		}
		else if(arr[left][right] == key)
		{
			return 1;
		}
		else
			right--;
	}
	return 0;

}
int main()
{
	int arr[ROW][COL] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int key = 8;
	int ret = Findnum(arr, ROW, COL, key);
	if (1 == ret)
	{
		printf("找到了！\n");
	}
	else
		printf("找不到!\n");
	return 0;
}
