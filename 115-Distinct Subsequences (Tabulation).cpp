class Solution {
public:
    vector<vector<int>> memo;
    int numDistinct(string s, string t) 
    {
        vector<vector<int>> memo(s.length()+1,vector<int>(t.length()+1,0));
        for(int i=0;i<=s.length();i++)
            memo[i][0]=1;
        for(int i=1;i<=s.length();i++)
            for(int j=1;j<=t.length();j++)
                memo[i][j]=s[i-1]==t[j-1]?memo[i-1][j-1]+memo[i-1][j]:memo[i-1][j];
                
        return memo[t.s.length()][t.length()];
    }
};