#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 0);
		dp[0] = nums[0];
		int maxn = nums[0];
		for (int i = 1; i<len; ++i)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			maxn = max(dp[i], maxn);
		}
		return maxn;
	}
};
