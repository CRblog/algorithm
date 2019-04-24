#include<stdio.h>
#include<stdlib.h>
int array[10] = {1,3,2,6,9,5,4,0,7,8};
int length = sizeof(array)/sizeof(array[0]);

void bubblesort(int* array){
  for(int i=0;i<length;i++)
    //每次会将最大的放到最后，所以数组多大就有多少个循环
  {
    for(int j = 0;j<length-i;j++)
      //每次循环都只用进行到第length-i次，因为循环每进行一次，就会有一个最后的值已经排好不需要再移动
        {
            if(array[j]>array[j+1])  //交换值就可以
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

