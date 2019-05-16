#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	cout<<"请输入 1<=a<=100 或 1<=b<=100 或 1<=c<=100"<<endl;
	cin>>a>>b>>c;
	if((1<=a&&a<=100)&&(1<=b&&b<=100)&&(1<=c&&c<=100))
	{
		if(a+b>c&&a+c>b&&c+b>a)
		{
			if(a==b&&a==c&&c==b){cout<<"三角形为等边三角形"<<endl;
			}
			else if(a==b||a==c||b==c)
			{
				cout<<"三角形为等腰三角形"<<endl;
			}
			else if((a*a+b*b)==c*c||(c*c+b*b)==a*a||(a*a+c*c)==b*b)
			{
				cout<<"三角形为直角三角形"<<endl;
			}
			else cout<<"a,b,c可组成三角形"<<endl;
		}
		else cout<<"不存在a,b,c组成的三角形"<<endl;
	}
	else cout<<"a或b或c的值不合法，无法判断"<<endl;
	return 0;
}
