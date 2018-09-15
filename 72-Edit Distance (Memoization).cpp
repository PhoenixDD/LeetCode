class Solution {
public:
    vector<vector<int>> memo;
    int dp(int i,int j,string &a,string &b)
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(i==0)
            return memo[i][j]=j;
        else if(j==0)
            return memo[i][j]=i;
        else if(a[i-1]==b[j-1])
            return memo[i][j]=dp(i-1,j-1,a,b);
        return memo[i][j]=1+min(min(dp(i-1,j-1,a,b),dp(i,j-1,a,b)),dp(i-1,j,a,b));
    }
    int minDistance(string word1, string word2)
    {
        memo.resize(word1.length()+1,vector<int>(word2.length()+1,-1));
        return dp(word1.length(),word2.length(),word1,word2);
    }
};