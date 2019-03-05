#include<iostream>
using namespace std;
class clas1{
public:
void func1()
{
	cout<<"AAA"<<endl;
}
};
class clas2
{
	public:
		void func2()
		{
			cout<<"BBB"<<endl;
		}

};
class clas3:public clas1
{
	public:
		void func3()
		{
		cout<<"CCC"<<endl;
		}
};
class clas4:public clas1,public clas2
{
	public:
		void func4()
		{
			cout<<"DDD"<<endl;
		}
};
int main()
{
	clas1 objec1;
	clas2 objec2;
	clas3 objec3;
	clas4 objec4;
	objec1.func1();
	objec2.func2();
	objec3.func1();
	objec3.func3();
	objec4.func1();
	objec4.func2();
	objec4.func4();
	return 0;
}
