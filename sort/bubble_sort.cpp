#include<stdio.h>
#include<stdlib.h>
int array[10] = {1,3,2,6,9,5,4,0,7,8};
int length = sizeof(array)/sizeof(array[0]);

void bubblesort(int* array){
  for(int i=0;i<length;i++)
    //ÿ�λὫ���ķŵ����������������ж��ٸ�ѭ��
  {
    for(int j = 0;j<length-i;j++)
      //ÿ��ѭ����ֻ�ý��е���length-i�Σ���Ϊѭ��ÿ����һ�Σ��ͻ���һ������ֵ�Ѿ��źò���Ҫ���ƶ�
        {
            if(array[j]>array[j+1])  //����ֵ�Ϳ���
            {
              int tmp = array[j];
              array[j] = array[j+1];
              array[j+1] = tmp;
            }
        }
  }
  for(int i=0;i<length;i++)
  {
    printf("%d ",array[i]);
  }
}
int main()
{
  bubblesort(array);
  return 0;
}

