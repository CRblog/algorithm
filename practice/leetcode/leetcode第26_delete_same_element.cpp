
//ɾ�����������е��ظ���
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�
ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬
�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
        {
            return 0;
        }
        int k=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]!=nums[k]){
                nums[++k] = nums[i];
            }
        }
        return k+1;
    }
};
