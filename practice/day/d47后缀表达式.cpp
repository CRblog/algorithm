#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        stack<int> st;
        for(int i=0;i<n;++i)
        {
            int sum = 0;
            string ch;
            cin>>ch;
            if(ch[0] == '+'|| ch[0] == '-' || ch[0] == '*' || ch[0] == '/' )
            {
                int st1 = st.top();
                st.pop();
                int st2 = st.top();
                st.pop();
                if(ch[0]=='+')
                    sum = st2+st1;
                else if(ch[0]=='-')
                    sum = st2-st1;
                else if(ch[0]=='*')
                    sum = st2*st1;
                else if(ch[0]=='/')
                {
                    if(st1!=0)
                        sum = st2/st1;
                    else
                        return 0;
                }

                st.push(sum);
            }
            else
                st.push(atoi(ch.c_str()));
        }
        cout<<(int)st.top()<<endl;
    }
    return 0;
}
