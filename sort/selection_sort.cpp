#include<iostream>
#include<cstring>
using namespace std;

int array[10] = {1,3,2,6,9,5,4,0,7,8};
int length = sizeof(array)/sizeof(array[0]);

void SelectionSort(int* array){
//����ѭ������һ��ѭ����ʾ���ڵ����±�Ϊi�����֣�����ѭ����ʼΪ0������Ϊlength-1
//�ڶ���ѭ����Ҫ�ҵ�ʣ�µ��е���Сֵ��������Ҫѭ��length-i�Σ���ʼΪi+1,����Ϊlength-1
for(int i=0;i<length;i++)
{
  int t = i;
  for(int j=i+1;j<length;j++)
  {
    if(array[j]<array[t])
    {
      t = j;
  //�ҵ�δ�����е���Сֵ
    }
  }
  if(t!=i)//
  {
    array[t]^=array[i];
    array[i]^=array[t];
    array[t]^=array[i];
  }
}
for(int i=0;i<length;i++)
{
  cout<<" "<<array[i];
}
}
int main()
{
  SelectionSort(array);
  return 0;
}

