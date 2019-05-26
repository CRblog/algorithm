#include<vector>
#include<iterator>
#include<cctype>
#include<iostream>
#include<string>
using namespace std;

void printfvector(const vector<int>& v)
{
  for(auto& e : v)
  {
    cout<<e<<" ";
  }
  cout<<endl;
}
int main()
{
  vector<int> v1(5,2);
  vector<int> v2(5,9);
  cout<<"初始化v1-v2"<<endl;
  printfvector(v1);
  printfvector(v2);
  swap(v1,v2);//全局交换函数
  cout<<"全局修改v1-v2"<<endl;
  printfvector(v1);
  printfvector(v2);
  v1.swap(v2);//函数交换
  cout<<"函数修改v1-v2"<<endl;

  //两种方式交换本质相同，都是调用v1.swap(v2)
  //通用全局函数：swap(T& v1,T& v2)---->{T temp = v1; v1 = v2; v2 = temp}
  //释放空间：
  //1：{
  //    vector<int> v2;
  //    v2.swap(v1);
  //   }加括号的作用是调用析构函数,相当于将局部变量和全局变量交换，出了作用域之后调用析构函数将v2释放
  //2:v1.shrink_to_fit();
  printfvector(v1);
  printfvector(v2);
  return 0;
}

