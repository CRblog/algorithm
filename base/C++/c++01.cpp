#include<iostream>
using namespace std;

/*
 * 引用：
 *    使用场景：
 *          1.做参数
 *            void Swap(int& x1,int& x2)
 *            {
 *              int x = x1;
 *              x1 = x2;
 *              x2 = x;
 *            }
 *          2.做返回值
 *          返回值加引用的意义：
 *          int& TestRefReturn(const int& a)
 *          {传引用返回
 *             a+=10;
 *             return a;//返回a的别名，不需要开辟临时变量
 *          }
 *          int TestRefReturn(int a)
 *          {传值返回
 *            a+=10;
 *            return a;//返回a的拷贝，需要开辟临时变量
 *          }
 *    指针和引用的区别：
 *         1.引用在定义时必须初始化，指针没有要求。
 *         2.引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型的实体。
 *         3.没有NULL引用，有NULL指针
 *         4.在sizeof中含义不同，引用结果为引用类型的大小，但指针始终是地址空间所占字节个数（32位平台下占4个字节）
 *         5.引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
 *         6.有多级指针，但没有多级引用
 *         7.访问实体方式不同，指针需要显式解引用，引用编辑器自己处理
 *         8.引用比指针使用起来相对更安全
 *    内联函数：
 *         以inline修饰的函数
 *        1.inline是一种以空间换时间的做法，省去调用函数额外开销，所以代码很长或者有循环/递归的函数不适宜使用作为内联函数
 *        2.inline对于编译器只是一个建议，如果出现循环/递归等，编译器会自动忽略掉内联
 *
 *
 *        宏的优缺点：
 *     错误写法：   #define MAX a>b?a:b
 *     正确写法：   #define MAX(a,b) ((a)>(b)?(a):(b))
 *
 *     typedef void (*FUNC)();  函数指针
 *          优点：
 *              1.增强代码的复用性
 *              2.提高性能
 *          缺点：
 *              1.不方便调试宏
 *              2.导致代码可读性差
 *              3.没有类型安全的检查
 *        替换宏：
 *            1.const 替换常量
 *            2.enum  替换常量
 *            3.inline 替换宏函数
 *        inline int Add(int a,int b)
 *         {
 *            int c = a+b;
 *            return c;
 *         }
 *         int main(){
 *         int ret = Add(1,2);
 *         return 0;
 *         }
 *    类和对象：
 *      C语言是面向过程的，关注的是过程
 *      C++是基于面向对象的，关注的是对象之间的交互
 *    类的定义
 *      class className{
 *     }
 *     c语言中的结构体：
 *
 *        struct ListNode{
 *            int _data;
*          struct ListNode* _next;
*          struct ListNode* _prev;
 *       };
*
*     C中：
*     类型：struct ListNode
*     C++中：
*     struct 升级成类,类型：ListNode
*     struct 类里面即可以定义变量，也可以定义函数
*
*     class 和 struct的区别：
*       class  默认私有
*       struct 默认公有
 *
 *
 *
 *
 * */
int main(){

  return 0;
}

