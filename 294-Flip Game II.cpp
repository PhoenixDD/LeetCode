static unordered_map<string,bool> memo;
class Solution {
public:
    bool dp(string &s)
    {
        if(memo.count(s))
            return memo[s];
        for(int i=0;i<(int)s.length()-1;i++)
            if(s[i]=='+'&&s[i+1]=='+')
            {
                s[i]='-',s[i+1]='-';
                if(!dp(s))
                {
                    s[i]='+',s[i+1]='+';
                    return memo[s]=true;
                }
                s[i]='+',s[i+1]='+';
            }
        return memo[s]=false;
    }
    bool canWin(string s) {
        if(s.size()<2)
            return false;
        for(int i=0;i<s.length()-2;i++)
            if(s[i]=='-'&&s[i+1]=='+'&&s[i+2]=='-')
                s[i+1]='-',i+=1;
        if(s.back()=='+'&&s[s.size()-2]=='-')
            s.pop_back();            
        if(s.back()=='-')
            s.pop_back();
        string seperated_S;
        for(int i=0;i<s.length();i++)
            if(s[i]=='-'&&s[i+1]=='+'||s[i]=='+')
                seperated_S+=s[i];
        //All Steps above compress the string to be seperated by single '-' between groups of '+';
        return dp(seperated_S);
    }
};