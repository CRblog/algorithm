#include<iostream>
using namespace std;

int main()
{
    int n;
    int s1,s2;
    while(cin>>n&&n!=0)
    {
	    int ans = 0;
        while(n>=3)
        {
        	s1 = n/3;
			s2 = n%3;
			ans += s1;
			n= s2+s1;
        }
        if(n==2)
        {
        	ans+=1;
		}
        cout<<ans<<endl;
    }
    return 0;
}
