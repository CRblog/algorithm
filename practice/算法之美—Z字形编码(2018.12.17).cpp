// Z���α��ţ�������ͼ��ѹ��JPEG
//
//���������
//1.�����ά�����е�Ԫ��matrix[i][j]��������j��ż����
//��i=0����i=7����ô����·���ھ����е��������ˮƽ�����ƶ�һ��
//2.�����ά�����е�Ԫ��matrix[i][j]��������i��������
//��j=0����j=7����ô����·���ھ����е�������Ǵ�ֱ�����ƶ�һ��
//3.�������������������������ά�����е�Ԫ��matrix[i][j]�ĺ��������i+j��ż����
//�����·���ھ����е�����������½��ƶ�һ��
#include<iostream>
#include<iomanip>

using namespace std;

#define SIZE 8

int main(int argc,char** argv){
	int matrix[SIZE][SIZE] = {0};
	int a[SIZE][SIZE] = {0};//�����ʼ��
	
	int i,j,x,y,value = 0;
	int *p;
	p = &matrix[0][0];
	//��ʼ������
	for(i=0;i<SIZE*SIZE;i++)
	{
		*p++ = i;
	}
		
	//��ӡԭʼ����
	cout<<"ԭʼ��������:"<<endl;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			cout<<setw(4)<<*(*(matrix + i)+j);
		}
		cout<<endl;
	}
	i=0;j=0;
	//����z���α���
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
	cout<<endl<<"����z���α��ź�ľ�������:"<<endl;
	for(i = 0;i<SIZE;i++)
	{
		for(j = 0 ;j<SIZE;j++)
			cout<<setw(4)<<*(*(a+i)+j);
		cout<<endl;
	}
	return 0;
}
