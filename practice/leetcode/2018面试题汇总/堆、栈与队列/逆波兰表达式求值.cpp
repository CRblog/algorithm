class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();++i)
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
            {
                st.push(atoi(tokens[i].c_str())); //这里还是要转化一下整数的，不然无法通过
            }
            else
                if(!st.empty())
                {
                    int sum;
                    int right = st.top();
                    st.pop();
                    int left = st.top();
                    st.pop();
                    if(tokens[i]=="+")
                        sum = left+right;
                    else if(tokens[i]=="-")
                        sum = left-right;
                    else if(tokens[i]=="*")
                        sum = left*right;
                    else if(tokens[i]=="/")
                        sum = left/right;
                    st.push(sum);
                }
        }
        return st.top();
    }
};
