class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum,tmp;
        if(num2==0)
            return num1;
        sum = num1^num2;
        tmp = (num1&num2)<<1;
        return Add(sum,tmp);
    }
};
