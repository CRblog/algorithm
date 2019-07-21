#include<bits\stdc++.h>
using namespace std; 
class Solution {
public:
	int longestSubstring(string s, int k) {
		vector<int> vect(26, 0);
		bool flag = false;
		int sum = 0;
		for (int i = 0; i<s.length(); i++)
		{
			vect[s[i] - 'a']++;
		}
		for (int i = 0; i<s.length(); i++)
		{
			if (vect[s[i] - 'a']<k)
			{
				flag = true;
				sum = max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i + 1, s.length()), k));
				break;
			}

		}
		if (!flag)  //·µ»ØÌõ¼þ
		{
			return s.length();
		}
		return sum;
	}
};
