#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int od = 1;int ev = 0;
        while(od<len&&ev<len)
        {
            while(arr[ev]%2==0)
            {
                ev+=2;
            }
            while(arr[od]%2==1)
            {
                od+=2;
            }

            if(od<len&&ev<len)
            {
                swap(arr[od],arr[ev]);
            }
        }

    }
    int main()
    {
		vector<int> arr;
		int len = 11;
		for(int i=0;i<len;i++)
    	{
    		cin>>arr[i];
		}
		oddInOddEvenInEven(arr,len);
    	for(int i=0;i<len;i++)
    	{
    		cout<<arr[i]<<endl;
		}
		return 0;
	}
