class Solution {
public:
    vector<vector<int>> memo;
    int dp(int m,int n)
    {
        if(m==0&&n==0)
            return memo[m][n]=1;
        if(memo[m][n]!=-1)
            return memo[m][n];
        if(m==0)
            return memo[m][n]=dp(m,n-1);
        if(n==0)
            return memo[m][n]=dp(m-1,n);
        return memo[m][n]=dp(m,n-1)+dp(m-1,n);
    }
    int uniquePaths(int m, int n) 
    {
        memo.resize(m,vector<int>(n,-1));
        return dp(m-1,n-1);
    }
};