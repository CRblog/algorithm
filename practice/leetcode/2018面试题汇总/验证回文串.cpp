class Solution {
public:
    //�´���һ���ַ���������ĸ�����ַŽ����������Ĳ���Ҫ�����ҽ���ĸ��Сдͳһ
    bool isPalindrome(string s) {
        int flag = 1;
        string st;
        for(int i=0;i<s.size();++i)
        {
            if((s[i]>=48 && s[i] <=57)||(s[i] >=97 && s[i] <= 122))
            {
                st.push_back(s[i]);
            }
            if(s[i]>=65 && s[i] <=90)
            {
                st.push_back(s[i] + 32);
            }
        }
        int lo = st.size();
        for(int i=0;i<lo;i++)
        {
            if(st[i]!=st[lo-1-i])
            {
                flag=0;
            }
        }
        if(flag==0)
            return false;
        else
            return true;
    }

};
