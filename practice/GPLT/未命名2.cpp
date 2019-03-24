#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;

struct pel{
	int huxi;
	int maibo;
    string name;
}pl[n];
 for(int i=0;i<n;i++)
 {
 	cin>>pl[i].name>>pl[i].huxi>>pl[i].maibo;
 }
 for(int i=0;i<n;i++)
 {
 	if(pl[i].huxi<15||pl[i].huxi>20||pl[i].maibo<50||pl[i].maibo>70)
		cout<<pl[i].name<<endl;
 }
  return 0;
}
