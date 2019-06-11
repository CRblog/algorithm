#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int main()
{
    string str1;
    while(cin>>str1)
    {
        reverse(str1.begin(),str1.end());
        cout<<str1<<endl;
    }
    return 0;
}
