#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b;
	c = a^b;
	d = (a&b)<<1;    //���λ
	cout<<c+d<<endl;
	return 0;
}
