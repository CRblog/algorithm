#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	cout<<"������ 1<=a<=100 �� 1<=b<=100 �� 1<=c<=100"<<endl;
	cin>>a>>b>>c;
	if((1<=a&&a<=100)&&(1<=b&&b<=100)&&(1<=c&&c<=100))
	{
		if(a+b>c&&a+c>b&&c+b>a)
		{
			if(a==b&&a==c&&c==b){cout<<"������Ϊ�ȱ�������"<<endl;
			}
			else if(a==b||a==c||b==c)
			{
				cout<<"������Ϊ����������"<<endl;
			}
			else if((a*a+b*b)==c*c||(c*c+b*b)==a*a||(a*a+c*c)==b*b)
			{
				cout<<"������Ϊֱ��������"<<endl;
			}
			else cout<<"a,b,c�����������"<<endl;
		}
		else cout<<"������a,b,c��ɵ�������"<<endl;
	}
	else cout<<"a��b��c��ֵ���Ϸ����޷��ж�"<<endl;
	return 0;
}
