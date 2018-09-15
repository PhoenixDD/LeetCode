class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> st;
        int temp,Max=0;
        st.push(0);
        for(char &c:s)
            if(c=='(')
                st.push(0);
            else
            {
                if(st.size()>1)
                {
                    temp=st.top(),st.pop();
                    Max=max(Max,st.top()+=temp+2);
                }
                else
                    st.top()=0;
            }
        return Max;
    }
};