#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;
typedef struct Heap{
  DataType* _array;
  int _capacity;
  int _size;
}Heap;
int Swap(DataType* pLeft,DataType* pRight){
    int tmp = *pLeft;
    *pLeft = *pRight;
    *pRight = tmp;
}
void AdjustDown(int  *array,int size,int parent){
    int child = parent*2+1;
    while(parent<size)
    {
      if(child+1<size&&array[child+1]<array[child])
      {
        child+=1;
      }
      if(array[child]<array[parent])
      {
        Swap(&array[child],&array[parent]);
        parent = child;
        child = parent*2+1;
      }
      else 
          return ;
    }
}
void CreateHeap(int array[],int size )
{
  for(int i=(size-2)/2;i>=0;--i)
  {
    AdjustDown(array,size,i);
  }
}
int TopK(int  array,int size,int k)
{
    CreateHeap(array,k);
    if(array[1])
}
int main()
{
   
}
