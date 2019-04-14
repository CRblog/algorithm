#include<iostream>
using namespace std;


/*
 *2.构造函数
      构造函数是特殊的成员函数，需要注意的是，构造函数虽然叫构造，但构造函数的主要任务不是开空间创建对象，而是初始化对象
      class Date
      {
      public:
          Date(int year,int month)   带参构造函数
          {
              _year = year;
              _month = month;
          }
          Date()  无参构造函数  默认构造函数
          {

          }
          Date()默认构造函数
          {
            _year = 1900;
            _month = 1;
            _day = 1;
          }
          默认构造函数不能共存，因为调用方式相同
          Date(int year =1900,int month = 1,int day = 1)   默认构造函数:全缺省
          {
                _year = year;
                _month = month;
                _day = day;
          }

          void setDate(int year,int month)
          {
            this->_year = year;
            this->_month = month;
          }
          void display()
          {
          cout<<this->_year<<"-"<<this->_month<<""<<endl;
          }
      private:
        int _year;
        int _month;

    编译器生成的默认构造函数会调用自定义类型的默认构造函数

    成员变量的命名风格：
          int _a;
          int m_a;
3.析构函数：

    与构造函数的功能相反，析构函数不是完成对象的销毁，局部对象销毁工作是由编译器完成的，而对象在销毁时会自动调用析构函数，完成类的一些资源清理工作.
    析构函数是特殊的成员函数
    ~Date()
    {
        cout<<"~Date()"<<endl;
    }
4.拷贝构造函数
    Date(const Date& d1)
    {
      _year = d1._year;
      _month = d1._month;
    }
    int main()
    {
       Date d1(2019,3);
       Date d2(d1);
       return 0;
    }
5.赋值运算符重载
    运算符重载：
          int operator+(Date& a,int b);//必须有一个类类型的，或者枚举类型的
          {
              return d1._month+b;
          }
          bool operaptor==(Date& d1,Date& d2)
          {
              return d1._year == d2._year&&
                     d1._month == d2._month;
          }

    .*、::、sizeof、?:、.   这五个运算符不能重载
 *
 *   赋值运算符重载
 *        void operator=(const Date& d1)
 *        {
 *         _year = d1.year;
 *         _month = d1._month;
 *         }
 *     1.参数类型
 *     2.返回值
 *     3.是否自己给自己赋值
 *     4.返回*this
 *     5.一个类如果没有显示定义赋值运算符重载，编译器也会生成一个，完成对象按字节序的值拷贝.
 *6.内部类：
      一个类定义在另一个类的内部


 * */

int main(){
  Date d1(2019,3);
  Date d3;  //无参构造函数的调用
  d1.display();
  return 0;
}

