#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int fib(int n)//�ǵݹ�ʵ��쳲�����
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
int dg_fib(int r)//�ݹ�ʵ��쳲�����
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
int rw(int n,int k)//n��k�η�
{
	if(k==0)
		return 1;
	else
		return n*rw(n,k-1);
}
int DigitSum(int n)//���������������֮��
{
	if(n>9)
	{
	return n%10+DigitSum(n/10);
	}
	else
		return n;
}
int reverse_string(char* string)//�ݹ�ʵ�ַ�ת�ַ�
{
	if(*string!='\0'){
		string++;//���ȼ�
		reverse_string(string);
		printf("%c",*(string-1));
		}
}
int  str(char* string)//�ַ�������strlen
	{
	int count=0;
	while(*string!='\0')
	{
		count++;
		string++;
	}
	return count;
}

int dg_str(char* string)//�ݹ�ʵ���ַ�������
{
	if(*string=='\0')
	{
		return 0;
	}
	return dg_str(string+1)+1;
}
int dir(int n)	//�ǵݹ�ʵ��n�Ľ׳�
{
	int sum=1;
	for(int i= 1;i<=n;i++)
	{
		sum*=i;
	}
	printf("%d\n",sum);
}

int dg_dir(int n)	//�ݹ�ʵ��n�Ľ׳�
{
	if(n==1)
	{
		return 1;
	}
	else
		return n*dg_dir(n-1);
}
int display(int n)	//��ӡ������ÿһλ
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
printf("�ǵݹ�ʵ��쳲�����:\n");
	int e;
	scanf("%d",&e);
	fib(e);

printf("�ݹ�ʵ��:\n");
	int r=0;
 	scanf("%d",&r);
	printf("%d\n",dg_fib(r));

printf("n��k�η�:\n");
    printf("%d\n",rw(2,4));

printf("���������������֮��:\n");
	int d;
	scanf("%d",&d);
	printf("%d\n",DigitSum(d));

printf("�ݹ�ʵ�ַ�ת�ַ�:\n");
	char* string = "asdasasg";
	reverse_string(string);

printf("�ַ�������strlen:\n");
	char* string1 = "asdasasg";
	printf("%d\n",str(string1));

printf("�ݹ�ʵ���ַ�������:\n");
	char* string2 = "asdasasg";
	printf("%d\n",dg_str(string2));

printf("�ǵݹ�ʵ��n�Ľ׳�:\n");
	int w;
	scanf("%d",&w);
	dir(w);
printf("�ݹ�ʵ��n�Ľ׳�:\n");

	printf("%d\n",dg_dir(w));

printf("��ӡ������ÿһλ:\n");
	int y;
	scanf("%d",&y);
	display(y);
	return 0;
}
