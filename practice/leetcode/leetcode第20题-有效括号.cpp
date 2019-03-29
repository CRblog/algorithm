class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_ch;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            switch(ch)
            {
                    case'(':
                    case'[':
                    case'{':
                        stack_ch.push(ch);
                        break;
                    case')':
                    case'}':
                    case']':
                    if(stack_ch.empty()){
                        return false;
                    }
                    char left = stack_ch.top();
                    if(!((left=='{'&&ch=='}')||(left=='('&&ch==')')||(left=='['&&ch==']')))
                       {
                           return false;
                       }
                       else
                       {
                           stack_ch.pop();
                       }
            }
        }
    if(stack_ch.empty())
                       {
                           return true;
                       }
                       else{
                           return false;
                       }
    }
};
