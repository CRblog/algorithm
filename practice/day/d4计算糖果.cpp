#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    int A,B,C;
    while(cin>>a>>b>>c>>d)
    {
        A=(a+c)/2;
        B=(b+d)/2;
        C = (d-b)/2;
        if(A+B==c&&B+C==d&&A-B==a&&B-C==b)
        {
        	cout<<A<<" "<<B<<" "<<C<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
    return 0;
}
