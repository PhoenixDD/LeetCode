class Solution {
public:
    vector<long> memo;
    int MOD=1e9+7;
    int numDecodings(string &s,int i)
    {
        if(i==0)
            return !s.empty();
        if(memo[i]!=-1)
            return memo[i];
        if(s[i-1]=='*')
        {
            memo[i]=(long)9*numDecodings(s,i-1);
            if(i>1&&s[i-2]=='1')
                memo[i]+=(long)9*numDecodings(s,i-2);
            else if(i>1&&s[i-2]=='2')
                memo[i]+=(long)6*numDecodings(s,i-2);
            else if(i>1&&s[i-2]=='*')
                memo[i]+=(long)15*numDecodings(s,i-2);
            return memo[i]%=MOD;
        }
        memo[i]=s[i-1]=='0'?0:numDecodings(s,i-1);
        if(i>1&&s[i-2]=='*')
            memo[i]+=s[i-1]<='6'?2*numDecodings(s,i-2):numDecodings(s,i-2);
        else if(i>1&&(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<='6'))
            memo[i]+=numDecodings(s,i-2);
        return memo[i]%=MOD;
    }
    int numDecodings(string s) 
    {
        memo.resize(s.length()+1,-1);
        return numDecodings(s,s.length());
    }
};