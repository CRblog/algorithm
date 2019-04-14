#include<bits/stdc++.h>
using namespace std;
/*

1.c/c++内存分布

 int globalVar = 1;
 static int staticGlobalVar = 1;
 void Test(){
      static int staticVar = 1;
      int localVar = 1;
      int num1[10] = {1,2,3,4};
      char char2[] = "abcd";
      char* pChar3 = "abcd";
      int* ptr1 = (int*)malloc(sizeof(int)*4);
      int* ptr2 = (int*)calloc(4,sizeof(int));
      int* ptr3 = (int*)realloc(ptr2,sizeof(int)*4);
      free(ptr1);
      free(ptr3);
      }
      栈，堆，数据段，代码段
      函数：栈
      全局数据：数据段（静态区）
      常量：代码段（常量区）
      glovalVar:数据段
      staticGlovalVar:数据段
      staticVar:数据段
      lovalVar:栈
      num1:栈
      char2:数组，栈上
      *char2:栈
      pChar3:栈
      *pChar3:代码段
      ptr1:栈
      *ptr1:堆（指向动态开辟的空间）
  sizeof(num1):   40
  sizeof(char2):  5（包括/0）
  strlen(char2):  4
  sizeof(pChar3): 4或者8（看操作系统）
 操作系统-> 虚拟进程地址空间->进程
    2^4=32位   2^8=64位
  strlen(pChar3):4
  sizeof(ptr1):4或8
  sizeof(ptr2):4或8

 strlen的实现：遇到/0结束，所以长度不算/0
   sizeof是操作符，计算的是数组的长度，包括/0
2.
 *
 *malloc/calloc/realloc和free
malloc: 开辟空间
calloc：开辟空间并初始化
realloc：调整大小，一般用于扩容
 *  1.原地扩容
 *  2.分开扩容
 *  int* p2 = (int*)malloc(4);
 *  int* p3 = (int*)realloc(p2,4);
 *  cout<<p2<<endl;
 *  cout<<p3<<endl;
 *  如果空间够就可以原地扩容（自动）
 *
3.C++内存管理方式
     内置类型：  malloc 和new效果一样
            都只是开辟空间
     自定义类型：  malloc 和new效果不同
     Test* p3 = new Test(100);
     Test* p4 = (Test*)malloc(sizeof(Test));
              new:开空间+调用构造函数初始化
              malloc只负责开辟空间，也没有初始化
     C++建议使用new

     delete p3;// 先析构，再释放空间
     free(p4);  //直接释放空间


4.operator new和 operator delete
   int* p1 = (int*)operator new(4);
   operator delete(p1);
   Test* p2 = (Test*)operator new(4);
   operator delete(p2);

   operator new --> malloc + 失败抛异常
   operator delete--> free

   例：
   try{
     void* p1 = malloc(0x7fffffff);
     void* p2 = operator new(0x7fffffff);
     cout<<p1<<endl;
     cout<<p2<<endl;
   }
catch(exception)
{
  cout<<e.what()<<endl;
}
5.1内置类型
      new int --->  operator new开空间->malloc->构造
      malloc int ->malloc

      new Test ->  operator new  ->  malloc -> 构造

      malloc Test -> malloc
5.2自定义类型
      new的原理：
         1.调用operator new
         2.在申请的空间上执行构造函数，完成对象的构造
      delete的原理:
         1.在空间上执行析构函数，完成对象中资源的清理工作
         2.调用operator delete函数释放对象的空间
      new  T[N]的原理：
         1.调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对象空间的申请
         2.在申请的空间上执行N次构造函数
      delete[]的原理：
         1.在释放的空间上执行N次析构函数，完成N个对象中资源的清理
         2.调用operator delete[] 释放空间，实际在operator delete[]中调用operator delete来释放空间

7.malloc/free和new/delete的区别：
      共同点：都是从堆上申请空间，并且需要用户手动释放
      不同点：
          1.malloc和free是函数，new和delete是操作符
          2.malloc申请的空间不能初始化，new可以初始化
          3.malloc申请空间时，需要手动计算空间大小并传递，new只需要在后面跟上空间的类型即可
          4.malloc的返回值位void*，在使用时必须强转，new不需要，new后跟的是空间的类型
          5.malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要捕获异常
          6.malloc/free只能申请内置类型的空间，不能申请自定义类型的空间，因为其不会调用构造与析构函数，而new可以，new在申请空间后会调用构造函数完成对象的构造，delete在释放空间前会调用析构函数完成空间中资源的清理
          7.malloc申请的空间一定在堆上，new不一定，因为operator new 函数可以重新实现
          8.new/delete 比malloc和free的效率稍微低点，因为new/delete的底层封装了malloc/free
 *
 *
 *
 *
 * */
int main(){

  return 0;
}

