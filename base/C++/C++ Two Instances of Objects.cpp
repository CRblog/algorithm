#include<iostream>
using namespace std;

class lwx{
	public:
		int age;
		int num;
};
int main()
{
	lwx ar[3];
	ar[1].age = 10;
	cout<<ar[1].age<<endl;
	return 0;
}
int main()
{
	lwx *p = new lwx[3];
	p[0].age = 10;
	p->age = 10;
	delete []p;
	p=NULL;
	return 0;
}



class A{
 public:
	void Set(int,int);
	int print();
 private:
	int _year;
 	int _day;
};
void A::Set(int year,int day)
{
	_year = year;
	_day = day;
}
int A::print()
{
cout<<_year<<"-"<<_day<<endl;
}
int main()
{
	A a;
	a.Set(2019,100);
	a.print();
	return 0;
}


