// Z字形编排，常用于图像压缩JPEG
//
//三种情况：
//1.如果二维数组中的元素matrix[i][j]中纵坐标j是偶数，
//且i=0或者i=7，那么遍历路径在矩阵中的走向就是水平向右移动一格
//2.如果二维数组中的元素matrix[i][j]中纵坐标i是奇数，
//且j=0或者j=7，那么遍历路径在矩阵中的走向就是垂直向下移动一格
//3.除上述规则以外的情况，如果二维数组中的元素matrix[i][j]的横纵坐标和i+j是偶数，
//则遍历路径在矩阵中的走向就是左下角移动一格。
#include<iostream>
#include<iomanip>

using namespace std;

#define SIZE 8

int main(int argc,char** argv){
	int matrix[SIZE][SIZE] = {0};
	int a[SIZE][SIZE] = {0};//数组初始化
	
	int i,j,x,y,value = 0;
	int *p;
	p = &matrix[0][0];
	//初始化矩阵
	for(i=0;i<SIZE*SIZE;i++)
	{
		*p++ = i;
	}
		
	//打印原始矩阵
	cout<<"原始矩阵如下:"<<endl;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			cout<<setw(4)<<*(*(matrix + i)+j);
		}
		cout<<endl;
	}
	i=0;j=0;
	//进行z字形编排
	for(x = 0;x<SIZE;x++)
		for(y = 0;y<SIZE;y++)
		{
			*(*(a+i)+j) = *(*(matrix + x) + y);
			if((i == SIZE-1||i==0) && j%2 == 0)
			{
				j++;
				continue;
			}
			if((j == 0||j == SIZE-1) && i%2 == 1)
			{
				i++;
				continue;
			}
			if((i+j)%2==0)
			{
				i--;
				j++;
			}
			else if((i+j)%2 == 1)
			{
				i++;
				j--;
			}
		}
	cout<<endl<<"经过z字形编排后的矩阵如下:"<<endl;
	for(i = 0;i<SIZE;i++)
	{
		for(j = 0 ;j<SIZE;j++)
			cout<<setw(4)<<*(*(a+i)+j);
		cout<<endl;
	}
	return 0;
}
