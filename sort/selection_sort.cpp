#include<iostream>
#include<cstring>
using namespace std;

int array[10] = {1,3,2,6,9,5,4,0,7,8};
int length = sizeof(array)/sizeof(array[0]);

void SelectionSort(int* array){
//两层循环，第一层循环表示正在调整下标为i的数字，所以循环开始为0，结束为length-1
//第二层循环是要找到剩下的中的最小值，所以需要循环length-i次，开始为i+1,结束为length-1
for(int i=0;i<length;i++)
{
  int t = i;
  for(int j=i+1;j<length;j++)
  {
    if(array[j]<array[t])
    {
      t = j;
  //找到未排序中的最小值
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

