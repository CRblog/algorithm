class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> res;
        if(nums.empty())
        {
            return nums;
        }
        else
        {
             int maxn = -9999;
            for(int i=0;i<k;i++)
            {
               maxn = max(maxn,nums[i]);

            }
            res.push_back(maxn);
            for(int i = k;i<nums.size();++i)
            {
                maxn = -9999;
                for(int j = k-1;j>=0;--j)
                {
                    maxn = max(maxn,nums[i-j]);
                }
                res.push_back(maxn);
            }
            return res;
        }
    }
};
