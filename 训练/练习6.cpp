#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int fib(int n)//非递归实现斐波那契
{
	int f[10000]={0};
	f[0]=1;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	cout<<f[n]<<endl;
}
int dg_fib(int r)//递归实现斐波那契
{
	if(r<2)
	{
		return 1;
	}
	else
	{
		return dg_fib(r-1)+dg_fib(r-2);
	}
}
int rw(int n,int k)//n的k次方
{
	if(k==0)
		return 1;
	else
		return n*rw(n,k-1);
}
int DigitSum(int n)//返回组成它的数字之和
{
	if(n>9)
	{
	return n%10+DigitSum(n/10);
	}
	else
		return n;
}
int reverse_string(char* string)//递归实现反转字符
{
	if(*string!='\0'){
		string++;//长度加
		reverse_string(string);
		printf("%c",*(string-1));
		}
}
int  str(char* string)//字符串长度strlen
	{
	int count=0;
	while(*string!='\0')
	{
		count++;
		string++;
	}
	return count;
}

int dg_str(char* string)//递归实现字符串长度
{
	if(*string=='\0')
	{
		return 0;
	}
	return dg_str(string+1)+1;
}
int dir(int n)	//非递归实现n的阶乘
{
	int sum=1;
	for(int i= 1;i<=n;i++)
	{
		sum*=i;
	}
	printf("%d\n",sum);
}

int dg_dir(int n)	//递归实现n的阶乘
{
	if(n==1)
	{
		return 1;
	}
	else
		return n*dg_dir(n-1);
}
int display(int n)	//打印整数的每一位
{
	if(n<=9)
	{
		printf("%d ",n%10);
	}
	else
	{
		display(n/10);
		printf("%d ",n%10);
	}

}
int main()
{
printf("非递归实现斐波那契:\n");
	int e;
	scanf("%d",&e);
	fib(e);

printf("递归实现:\n");
	int r=0;
 	scanf("%d",&r);
	printf("%d\n",dg_fib(r));

printf("n的k次方:\n");
    printf("%d\n",rw(2,4));

printf("返回组成它的数字之和:\n");
	int d;
	scanf("%d",&d);
	printf("%d\n",DigitSum(d));

printf("递归实现反转字符:\n");
	char* string = "asdasasg";
	reverse_string(string);

printf("字符串长度strlen:\n");
	char* string1 = "asdasasg";
	printf("%d\n",str(string1));

printf("递归实现字符串长度:\n");
	char* string2 = "asdasasg";
	printf("%d\n",dg_str(string2));

printf("非递归实现n的阶乘:\n");
	int w;
	scanf("%d",&w);
	dir(w);
printf("递归实现n的阶乘:\n");

	printf("%d\n",dg_dir(w));

printf("打印整数的每一位:\n");
	int y;
	scanf("%d",&y);
	display(y);
	return 0;
}
