class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //���ֵĴ�������һ��������������м��һ���������
        int len = nums.size();
        sort(nums.begin(),nums.end());
        return nums[len/2];
    }
};
