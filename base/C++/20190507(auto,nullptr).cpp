#include<iostream>
#include<cstdlib>
using namespace std;

//#define MAX(a,b) ((a)>(b)?(a):(b))

/*int main(){
	int a = 10;
	int b = 20;
	cout << MAX(a, b) << endl;
	cout << MAX(b, a) << endl;
	cout << MAX(++b, a) << endl;
	system("pause");
	return 0;

}*/
//��������
//inline int add(int left,int right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a = 20;
//	int b = 10;
//	cout << add(a, b) << endl;
//	system("pause");
//	return 0;
//}
//���������ͺ����ȱ��

//auto�ؼ���
int main()
{
	auto a = 10;
	cout << typeid(a).name() << endl;    //  int 
	auto b = 33.14;
	cout << typeid(b).name() << endl;    //  double
	system("pause");
	return 0;
}