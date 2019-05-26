class Solution {
public:
    int StrToInt(string str) {
        int flag = 1;
        int sum = 0;
        int len = str.size();
        for(int i=0;i<len;i++)
        {
            if(str[i]<='9'&&str[i]>='0')
            {
                sum = sum*10+(str[i]-'0');
            }
            else if(str[i]=='-')
            {
                flag = -1;
            }
            else if(str[i]=='+')
            {
                flag = 1;
            }
            else
                return 0;
        }
        return flag*sum;
    }
};
