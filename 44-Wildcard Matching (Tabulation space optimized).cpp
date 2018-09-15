class Solution {
public:
    bool isMatch(string s, string p) 
    {
        bool initial=false,prev,temp;
        vector<bool> memo(s.length()+1,false);
        int x=0;
        memo[0]=true;
        if(p[x]=='*')
            initial=true;
        while(p[x++]=='*');
        if(initial)
            fill(memo.begin(),memo.end(),true);
        for(int j=x;j<=p.length();j++)
        {
            prev=memo[0];
            memo[0]=false;
            for(int i=1;i<=s.length();i++)
            {
                temp=memo[i];
                if(p[j-1]=='*')
                    memo[i]=memo[i]||memo[i-1];
                else if(p[j-1]=='?')
                    memo[i]=prev;
                else
                    memo[i]=s[i-1]==p[j-1]&&prev;
                prev=temp;
            }
        }
        return memo[s.length()];
    }
};