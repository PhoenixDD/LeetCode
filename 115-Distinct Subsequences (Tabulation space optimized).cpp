class Solution {
public:
    vector<long> memo;
    int numDistinct(string s, string t)
    {
        memo.resize(t.length()+1,0);
        memo[0]=1;
        for(int i=1;i<=s.length();i++)
            for(int j=i<t.length()?i:t.length();j>0;j--)
                memo[j]+=s[i-1]==t[j-1]?memo[j-1]:0;
        return memo[t.length()];
    }
};