class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> minstack(k);
        for(int i=0;i<k;i++)
        {
            minstack[i]=nums[i];
        }
        make_heap(minstack.begin(),minstack.end(),greater<int>());
        for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>minstack[0])
            {
                minstack.push_back(nums[i]);
                push_heap(minstack.begin(),minstack.end(),greater<int>());
            }
            if(minstack.size()>k)
            {
                pop_heap(minstack.begin(),minstack.end(),greater<int>());
                minstack.pop_back();
            }
        }
        return minstack[0];
    }
};
