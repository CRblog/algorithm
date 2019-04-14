#include<iostream>
using namespace std;

template<class T>
void Swap(T& x1,T& x2)
{
  T tmp = x1;
  x1 = x2;
  x2 = tmp;
}

int main()
{
  int a =0,b=1;
  double aa = 1.11,b=2.22;
  Swap(a,b);   //Swap<int>
  Swap(aa,bb);//Swap<double>
}



/*
 *1.���ͱ��
    ģ�壺����ģ�����ģ��

  2.����ģ��
    template<typename T>   //typename ����class����
    void Swap(T& left,T& right)
    {
        T temp = left;
        left = right;
        right = temp;
    }




 * */



