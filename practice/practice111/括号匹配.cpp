#include<bits/stdc++.h>
using namespace std;
int aaa(string s)
{
	int n1=0,n2=0,m1=0,m2=0,q1=0,q2=0;
    for(int i=0;i<s.size();i++)
     {
        if(s[i]=='(')
        {
            n1++;
        }
        if(s[i]==')')
        {
            n2++;
        }
        if(s[i]=='[')
        {
            m1++;
        }
        if(s[i]==']')
        {
            m2++;
        }
        if(s[i]=='{')
        {
            q1++;
        }
        if(s[i]=='}')
        {
            q2++;
        }
     }
        if(n1==n2&&q1==q2&&m1==m2)
        {
            cout<<n1<<n2<<m1<<m2<<q1<<q2<<endl;
        }
        else
        {
            cout<<n1<<n2<<m1<<m2<<q1<<q2<<endl;
        }
}
int main()
{
	string s ="([)]";
	aaa(s);
}

