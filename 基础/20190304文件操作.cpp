#include<bits/stdc++.h>
using namespace std;

20190304文件操作
磁盘（外存）相关联

文件：程序文件 数据文件
绝对路径：C:\ASD\ASD\AS\D\AS\D\
相对路径:   .\AWE.TXT
.表示当前路径
..表示当前路径的上级目录
后缀名不会对文件内容或者文件类型产生任何影响，只不过是告诉系统默认使用哪个程序进行操作
根据文件组织形式分为：二进制文件，文本文件(以ASCII码保存)

缓冲区的概念（内存）

文件指针

1.打开文件
fopen第一个参数是路径（绝对路径相对路径都行）
        第二个参数是打开方式：
		r 只读方式打开  w 只写方式打开 a 追加方式打开
      读写方式：r+ 或者 w+
 alt + g/F12/ctrl+左键  跳转到定义
文件指针也可以叫做 句柄handle
	fopen("E:/Dev-Cpp/NEWS.txt","r")

2.关闭文件
如果没有关闭文件，占用系统打开文件的数量
句柄泄露/资源泄露/文件描述符泄露
程序结束后自动关闭
fclose(fp)

3.读文件
fread 把磁盘读到内存中
char buf[1024]={0};//创建缓冲区
fread(buf,1,4,fp);
第一个变量：缓冲区    第二个：每个元素多少字节
第三个：多少个元素    第四个：文件
返回值是读到的个数


//4.写文件
从内存中写到磁盘
char buf[1024]= "aaa";
fwrite(buf,1,strlen(buf),fp);




字符输入函数：fgetc
字符输出    ：fputc
文本行输入  : fgets
文本行输出  : fputs
格式化输入  : fscanf
格式化输出  : fprintf
二进制输入  : fread
二进制输出  : fwrite


int main()
{
	FILE* fp = fopen("E:/123.txt","a+");
	if(fp == NULL)
	{
		printf("文件打开失败! %d\n",errno);
		perror("文件打开失败!");
		return 1;
	}
	char buf[1024]={0};//创建缓冲区
	fread(buf,1,4,fp);
	printf("%s",buf);

char buf[1024]= "aaab";
fwrite(buf,1,strlen(buf),fp);
	return 0;
}
