class Solution {
public:
    bool isValid(string s)
    {
        stack<char> bracks;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]==']'&&(bracks.empty()||bracks.top()!='['))||(s[i]=='}'&&(bracks.empty()||bracks.top()!='{'))||(s[i]==')'&&(bracks.empty()||bracks.top()!='(')))
                return false;
            else if(s[i]=='('||s[i]=='{'||s[i]=='[')
                bracks.push(s[i]);
            else
                bracks.pop();
        }
        return bracks.empty();
    }
};