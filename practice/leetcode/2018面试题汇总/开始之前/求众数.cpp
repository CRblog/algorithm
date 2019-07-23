class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //出现的次数大于一半则排序放在最中间的一定是这个数
        int len = nums.size();
        sort(nums.begin(),nums.end());
        return nums[len/2];
    }
};
