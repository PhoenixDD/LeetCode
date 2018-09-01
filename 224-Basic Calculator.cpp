class Solution {
public:
    int calculate(string s)
    {
        int temp=0,res=0;
        stack<int> st,op;
        int sign=1;
        for(char &c:s)
        {
            if(isdigit(c))
                    temp=temp*10+c-'0';
            else
            {
                res+=sign*temp;
                temp=0;
                if(c=='+')
                    sign=1;
                else if(c=='-')
                    sign=-1;
                else if(c=='(')
                {
                    st.push(res);
                    op.push(sign);
                    res=0,sign=1;
                }
                else if(c==')')
                {
                    res=res*op.top()+st.top();
                    st.pop(),op.pop();
                }
            }
        }
        return res+sign*temp;
    }
};