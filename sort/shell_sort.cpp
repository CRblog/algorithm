#include<iostream>
#include<cstring>
using namespace std;

int array[10] = {1,3,2,6,9,5,4,0,7,8};
int length = sizeof(array)/sizeof(array[0]);

void ShellSort(int* array)
{
  int end = length;
  int start  =0;
  int sign = end - start -1;
  do{
      sign = sign/3+1;
      for(int i=start+sign;i<length;i++ )
      {
        if(array[i]<array[i-sign])
        {
          int temp = array[i];//�Ѻ����ֵ���
          int j = i-sign;//��ǰλ��Ҳ�������
          do{
              array[j+sign] = array[j];//��ǰ��Ĵ�ֵ�ŵ����棬����֮ǰ��ֵ
              j-=sign;
        //������ǰ̽���������һ��signС�ڿ�ʼֵ����ֹͣѭ��,����ǰһ��ֵС�ڵ�ǰֵ��Ҳֹͣѭ��
          }while(j>=start&&array[j]>temp);
            array[j+sign] = temp;
          //�����ú���֮���ֵ�Ž���
        }
      }
  }while(sign>1);
  for(int i=0;i<length;i++)
  {
    cout<<" "<<array[i];
  }
}

int main()
{
  ShellSort(array);
  return 0;
}

