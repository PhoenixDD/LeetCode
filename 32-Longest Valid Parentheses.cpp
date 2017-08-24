class Solution {
public:
    int longestValidParentheses(string s)
    {
        stack<int> starting;
        int result=0;
        starting.push(-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                starting.push(i);
            else
            {
                starting.pop();
                if(!starting.empty())
                    result=max(result,i-starting.top());
                else
                    starting.push(i);
            }
        }
        return result;
    }
};