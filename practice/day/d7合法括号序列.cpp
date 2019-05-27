class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> s;
       for(int i=0;i<n;i++)
        {
            if(A[i]=='(')
            {
                s.push(A[i]);
            }
            else if(A[i]==')')
            {
                if(s.empty())
                {
                    return false;
                }
                else
                    s.pop();
            }
            else
                return false;
        }
       return s.empty();
    }
};

