//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int n,ans;
//    vector<int> v;
//    while(cin>>n)
//    {
//    	v.push_back(n);
//    	int count = 1;
//    	int tmp = v[0];
//    	for(int i=1;i<v.size();i++)
//    	{
//    		if(v[i]==tmp) count++;
//    		else    count--;
//    		if(count==0)
//				tmp = v[i],count++;
//ans = tmp;
//		}
//
//	}
//	cout<<ans<<endl;
//    return 0;
//}

#include<iostream>
using namespace std;
int main(){
    int a[1000]={0};
    int n,num=0;  
    while(cin>>n){
        a[n]++;
        num++;
    }
    for(int i=0;i<num;i++){
        if(a[i]>=num/2)
            cout<<i<<endl;
    }
    return 0;
}
