#incldue<iostream>
using namespace std;

/*

   class A{
   int _a;
   };

   int main()
   {
      A* pa = new A;
      delete pa;
      return 0;
   }

   */

class Heap
{
  friend void fun1();
  public:
      static Heap* getHeap()
      {
        return new Heap;
      }
      Heap(const Heap& hp) = delete;
  private:
      Heap(){}
};
//只能在堆上创建对象的类：
  //1.构造函数私有化
  //2.提供公共接口：在堆上创建对象
  //3.在类外无法创建对象，函数用类名调用，公共接口必须为static接口
  //4.防止拷贝：1）拷贝构造私有化，只声明不实现
  //            2）拷贝构造声明delete函数(C++11特性)
  //
  //
  //
//只能在栈上创建对象
 //new --->  operator new  -->构造
 //一：
 //   1.构造函数私有化，间接阻止new关键字的执行逻辑
 //   2.提供公共接口：在栈上创建对象
 //   3.在类外无法创建对象，函数用类名调用，公用接口必须为static 接口
 //二：
 //   1.重载operator new 函数，声明成私有的，并且不实现
 //   2.构造函数公有
class Stack
{
  public:
   static Stack getStack()
    {
      return Stack();
    }
  private:
    Stack()
    {}
};
int main()
{
  Stack s =Stack::new Stack;
  return 0;

}
 //二：
 //   1.重载operator new 函数，声明成私有的，并且不实现
 //   2.构造函数公有
 class Stack2
{
  public:
    //new-->operator  new
    void* operator new(size_t n) = delete;
  private:
    //void* operator new(size_t n);
}

int main()
{
  Stack s = Stack::getStack();
  Stack cp(s);
  Stack2 ps = new Stack2;
  return 0;
}




/*
 *单例模式：全局只有唯一一份
     一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享。
     两种实现模式：
          饿汉模式：
             优点：简单
             缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
  class Singleton
  {
    public:
        getInstance()
        {
            return &_sin;
        }
    private:
        Singleton(){}//构造函数私有化
       // Singleton(const Singleton& s); //防止拷贝函数
       Singleton(const Singleton& s) = delete;
       Singleton& operator = (const Singleton& s)
       {
          if(this != &s)
          {

          }
          return *this;
       }
       static Singleton _sin;
  };
  Singleton Singleton::_sin;

  int main()
  {
  Singleton* ps = Singleton::getInstance();
  Singleton s(*ps);
  return 0;
  }
          懒汉模式：
 * */

