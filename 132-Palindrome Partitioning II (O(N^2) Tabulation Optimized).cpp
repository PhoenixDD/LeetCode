class Solution {
public:
    int minCut(string s) 
    {
        if(s.empty())
            return 0;
        vector<int> memo(s.length()+1);
        for(int i=0;i<=s.length();i++)
            memo[i]=i-1;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;i-j>=0&&i+j<s.length()&&s[i-j]==s[i+j];j++)
                memo[i+j+1]=min(memo[i+j+1],1+memo[i-j]);
            for(int j=0;i-j-1>=0&&i+j<s.length()&&s[i-j-1]==s[i+j];j++)
                memo[i+j+1]=min(memo[i+j+1],1+memo[i-j-1]);
        }
        return memo[s.length()];
    }
};