#include<iostream>
using namespace std;


/*
 *2.���캯��
      ���캯��������ĳ�Ա��������Ҫע����ǣ����캯����Ȼ�й��죬�����캯������Ҫ�����ǿ��ռ䴴�����󣬶��ǳ�ʼ������
      class Date
      {
      public:
          Date(int year,int month)   ���ι��캯��
          {
              _year = year;
              _month = month;
          }
          Date()  �޲ι��캯��  Ĭ�Ϲ��캯��
          {

          }
          Date()Ĭ�Ϲ��캯��
          {
            _year = 1900;
            _month = 1;
            _day = 1;
          }
          Ĭ�Ϲ��캯�����ܹ��棬��Ϊ���÷�ʽ��ͬ
          Date(int year =1900,int month = 1,int day = 1)   Ĭ�Ϲ��캯��:ȫȱʡ
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

    ���������ɵ�Ĭ�Ϲ��캯��������Զ������͵�Ĭ�Ϲ��캯��

    ��Ա�������������
          int _a;
          int m_a;
3.����������

    �빹�캯���Ĺ����෴����������������ɶ�������٣��ֲ��������ٹ������ɱ�������ɵģ�������������ʱ���Զ���������������������һЩ��Դ������.
    ��������������ĳ�Ա����
    ~Date()
    {
        cout<<"~Date()"<<endl;
    }
4.�������캯��
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
5.��ֵ���������
    ��������أ�
          int operator+(Date& a,int b);//������һ�������͵ģ�����ö�����͵�
          {
              return d1._month+b;
          }
          bool operaptor==(Date& d1,Date& d2)
          {
              return d1._year == d2._year&&
                     d1._month == d2._month;
          }

    .*��::��sizeof��?:��.   ������������������
 *
 *   ��ֵ���������
 *        void operator=(const Date& d1)
 *        {
 *         _year = d1.year;
 *         _month = d1._month;
 *         }
 *     1.��������
 *     2.����ֵ
 *     3.�Ƿ��Լ����Լ���ֵ
 *     4.����*this
 *     5.һ�������û����ʾ���帳ֵ��������أ�������Ҳ������һ������ɶ����ֽ����ֵ����.
 *6.�ڲ��ࣺ
      һ���ඨ������һ������ڲ�


 * */

int main(){
  Date d1(2019,3);
  Date d3;  //�޲ι��캯���ĵ���
  d1.display();
  return 0;
}

