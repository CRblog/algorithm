class Solution {
public:
    //���캯��
    class Sum
    {
        public:
            Sum()
            {
                _sum+=_i;
                ++_i;
            }
    };
    int Sum_Solution(int n) {
        _sum=0;
        _i =1;
            Sum arr[n];//������n��
        return _sum;
    }
private:
    static int _sum;
    static int _i;
};
int Solution::_sum = 0;
int Solution::_i = 1;
