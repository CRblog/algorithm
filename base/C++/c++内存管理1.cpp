#include<bits/stdc++.h>
using namespace std;
/*

1.c/c++�ڴ�ֲ�

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
      ջ���ѣ����ݶΣ������
      ������ջ
      ȫ�����ݣ����ݶΣ���̬����
      ����������Σ���������
      glovalVar:���ݶ�
      staticGlovalVar:���ݶ�
      staticVar:���ݶ�
      lovalVar:ջ
      num1:ջ
      char2:���飬ջ��
      *char2:ջ
      pChar3:ջ
      *pChar3:�����
      ptr1:ջ
      *ptr1:�ѣ�ָ��̬���ٵĿռ䣩
  sizeof(num1):   40
  sizeof(char2):  5������/0��
  strlen(char2):  4
  sizeof(pChar3): 4����8��������ϵͳ��
 ����ϵͳ-> ������̵�ַ�ռ�->����
    2^4=32λ   2^8=64λ
  strlen(pChar3):4
  sizeof(ptr1):4��8
  sizeof(ptr2):4��8

 strlen��ʵ�֣�����/0���������Գ��Ȳ���/0
   sizeof�ǲ������������������ĳ��ȣ�����/0
2.
 *
 *malloc/calloc/realloc��free
malloc: ���ٿռ�
calloc�����ٿռ䲢��ʼ��
realloc��������С��һ����������
 *  1.ԭ������
 *  2.�ֿ�����
 *  int* p2 = (int*)malloc(4);
 *  int* p3 = (int*)realloc(p2,4);
 *  cout<<p2<<endl;
 *  cout<<p3<<endl;
 *  ����ռ乻�Ϳ���ԭ�����ݣ��Զ���
 *
3.C++�ڴ����ʽ
     �������ͣ�  malloc ��newЧ��һ��
            ��ֻ�ǿ��ٿռ�
     �Զ������ͣ�  malloc ��newЧ����ͬ
     Test* p3 = new Test(100);
     Test* p4 = (Test*)malloc(sizeof(Test));
              new:���ռ�+���ù��캯����ʼ��
              mallocֻ���𿪱ٿռ䣬Ҳû�г�ʼ��
     C++����ʹ��new

     delete p3;// �����������ͷſռ�
     free(p4);  //ֱ���ͷſռ�


4.operator new�� operator delete
   int* p1 = (int*)operator new(4);
   operator delete(p1);
   Test* p2 = (Test*)operator new(4);
   operator delete(p2);

   operator new --> malloc + ʧ�����쳣
   operator delete--> free

   ����
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
5.1��������
      new int --->  operator new���ռ�->malloc->����
      malloc int ->malloc

      new Test ->  operator new  ->  malloc -> ����

      malloc Test -> malloc
5.2�Զ�������
      new��ԭ��
         1.����operator new
         2.������Ŀռ���ִ�й��캯������ɶ���Ĺ���
      delete��ԭ��:
         1.�ڿռ���ִ��������������ɶ�������Դ��������
         2.����operator delete�����ͷŶ���Ŀռ�
      new  T[N]��ԭ��
         1.����operator new[]��������operator new[]��ʵ�ʵ���operator new�������N������ռ������
         2.������Ŀռ���ִ��N�ι��캯��
      delete[]��ԭ��
         1.���ͷŵĿռ���ִ��N���������������N����������Դ������
         2.����operator delete[] �ͷſռ䣬ʵ����operator delete[]�е���operator delete���ͷſռ�

7.malloc/free��new/delete������
      ��ͬ�㣺���ǴӶ�������ռ䣬������Ҫ�û��ֶ��ͷ�
      ��ͬ�㣺
          1.malloc��free�Ǻ�����new��delete�ǲ�����
          2.malloc����Ŀռ䲻�ܳ�ʼ����new���Գ�ʼ��
          3.malloc����ռ�ʱ����Ҫ�ֶ�����ռ��С�����ݣ�newֻ��Ҫ�ں�����Ͽռ�����ͼ���
          4.malloc�ķ���ֵλvoid*����ʹ��ʱ����ǿת��new����Ҫ��new������ǿռ������
          5.malloc����ռ�ʧ��ʱ�����ص���NULL�����ʹ��ʱ�����пգ�new����Ҫ������new��Ҫ�����쳣
          6.malloc/freeֻ�������������͵Ŀռ䣬���������Զ������͵Ŀռ䣬��Ϊ�䲻����ù�����������������new���ԣ�new������ռ�����ù��캯����ɶ���Ĺ��죬delete���ͷſռ�ǰ���������������ɿռ�����Դ������
          7.malloc����Ŀռ�һ���ڶ��ϣ�new��һ������Ϊoperator new ������������ʵ��
          8.new/delete ��malloc��free��Ч����΢�͵㣬��Ϊnew/delete�ĵײ��װ��malloc/free
 *
 *
 *
 *
 * */
int main(){

  return 0;
}

