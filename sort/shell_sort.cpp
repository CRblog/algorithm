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
          int temp = array[i];//把后面的值标记
          int j = i-sign;//当前位置也标记起来
          do{
              array[j+sign] = array[j];//将前面的大值放到后面，覆盖之前的值
              j-=sign;
        //继续往前探索，如果下一个sign小于开始值，就停止循环,或者前一个值小于当前值，也停止循环
          }while(j>=start&&array[j]>temp);
            array[j+sign] = temp;
          //调整好后面之后把值放进来
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

