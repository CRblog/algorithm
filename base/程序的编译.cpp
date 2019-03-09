#include<bits/stdc++.h>
using namespace std;

//程序的编译（预处理）

//VS叫做IDE集成开发环境
//包含了 代码编辑器，编译器，调试器，工程管理工具......
//msvc cl
//
//gcc 查理德.马修.斯托曼
//
//clang 苹果主导，开源编译器   LLVM
//
//每个.c文件称为一个编译单元
//
//1.预处理
//	a)拷贝头文件到.c中
//	b)宏替换
//	c)条件编译  处理其他的预处理指令（#pragma pack(4)）
//	d)去掉注释
//2.编译
//    把.c文件转换成汇编文件
//3.汇编
//    把汇编文件转换成二进制的机器指令（目标文件）
//4.链接
//    把所有的目标文件汇总在一起，并加入依赖库
// # 能够把 宏的参数 当作字符串字面值常量
//1
#define PRINT(val) \
printf(#val" = %d\n",val)
//2
#define ADD_TO_SUM(x,y) \
sum## x+= y;
int main()
{
//1
//    char* p = "aaaa""bbbb""cccc";
//    printf("%s\n",p);
//	PRINT(10 + 20);
//2
//	int sum1=10;
//	ADD_TO_SUM(1,10);
//	printf("%d",sum1);
//	__FILE__文件位置
//	__LINE__当前行数
//	__DATE__程序编译的日期
//	__TIME__程序编译的时间
//	__STDC__是否符合c语言标准

	return 0;
  }
  
