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
//ֻ���ڶ��ϴ���������ࣺ
  //1.���캯��˽�л�
  //2.�ṩ�����ӿڣ��ڶ��ϴ�������
  //3.�������޷��������󣬺������������ã������ӿڱ���Ϊstatic�ӿ�
  //4.��ֹ������1����������˽�л���ֻ������ʵ��
  //            2��������������delete����(C++11����)
  //
  //
  //
//ֻ����ջ�ϴ�������
 //new --->  operator new  -->����
 //һ��
 //   1.���캯��˽�л��������ֹnew�ؼ��ֵ�ִ���߼�
 //   2.�ṩ�����ӿڣ���ջ�ϴ�������
 //   3.�������޷��������󣬺������������ã����ýӿڱ���Ϊstatic �ӿ�
 //����
 //   1.����operator new ������������˽�еģ����Ҳ�ʵ��
 //   2.���캯������
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
 //����
 //   1.����operator new ������������˽�еģ����Ҳ�ʵ��
 //   2.���캯������
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
 *����ģʽ��ȫ��ֻ��Ψһһ��
     һ����ֻ�ܴ���һ�����󣬼�����ģʽ����ģʽ���Ա�֤ϵͳ�и���ֻ��һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㣬��ʵ�������г���ģ�鹲��
     ����ʵ��ģʽ��
          ����ģʽ��
             �ŵ㣺��
             ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����
  class Singleton
  {
    public:
        getInstance()
        {
            return &_sin;
        }
    private:
        Singleton(){}//���캯��˽�л�
       // Singleton(const Singleton& s); //��ֹ��������
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
          ����ģʽ��
 * */

