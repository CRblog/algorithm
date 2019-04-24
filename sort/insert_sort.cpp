#include<iostream>
#include<cstring>
using namespace std;

int array[10] = {1,3,2,6,9,5,4,0,7,8};
int length = sizeof(array)/sizeof(array[0]);

void InsertSort(int* array){
  for(int i=0;i<length;i++)
  {
    for(int j=0;j<i;j++)   //已经排好序是前J个数字
    {
      if(array[i]<array[j])
        //如果要排序的数字小于第J个，说明这个数字需要放进排序数组里，没有小于的话就刚好放在最后一个
      {
        int tmp = array[i];
        //标记要排序的数字，防止被覆盖后丢失

        for(int k = i-1;k>=j;--k)
        {
            array[k+1] = array[k];
        //找到大于它的最小数，然后大于它的所有数都往后移一位，这里需要从后往前移，不然后面的数据就会被覆盖
        }
        array[j] = tmp;
        //循环结束，将要插入的数字插入到合适位置
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

