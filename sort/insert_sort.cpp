#include<iostream>
#include<cstring>
using namespace std;

int array[10] = {1,3,2,6,9,5,4,0,7,8};
int length = sizeof(array)/sizeof(array[0]);

void InsertSort(int* array){
  for(int i=0;i<length;i++)
  {
    for(int j=0;j<i;j++)   //�Ѿ��ź�����ǰJ������
    {
      if(array[i]<array[j])
        //���Ҫ���������С�ڵ�J����˵�����������Ҫ�Ž����������û��С�ڵĻ��͸պ÷������һ��
      {
        int tmp = array[i];
        //���Ҫ��������֣���ֹ�����Ǻ�ʧ

        for(int k = i-1;k>=j;--k)
        {
            array[k+1] = array[k];
        //�ҵ�����������С����Ȼ�����������������������һλ��������Ҫ�Ӻ���ǰ�ƣ���Ȼ��������ݾͻᱻ����
        }
        array[j] = tmp;
        //ѭ����������Ҫ��������ֲ��뵽����λ��
      }
    }
  }
for(int i=0;i<length;i++)
{
  cout<<" "<<array[i];
}
}
int main()
{
  InsertSort(array);
  return 0;
}

