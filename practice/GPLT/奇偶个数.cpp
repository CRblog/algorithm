#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int m;
  int a1=0;
  int a2=0;
 for(int i=0;i<n;i++)
 {
   cin>>m;
   if(m%2==0)
   {
     a1++;
   }
   else{
     a2++;
   }
 }
 cout<<a2<<" "<<a1<<endl;
 return 0;
}
