class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>> memo;
    int dp(int n,int k)
    {
        if(n==0)
            return 0;
        if(k==0)
            return 1;
        if(memo[n][k]!=-1)
            return memo[n][k];
        return memo[n][k]=(dp(n-1,k)+(dp(n,k-1)-(k-n+1>=0?dp(n-1,k-n+1):0)+MOD)%MOD)%MOD;
    }
    int kInversePairs(int n, int k) 
    {
        memo.resize(n+1,vector<int>(k+1,-1));
        return (dp(n,k)-(k>=n?dp(n,k-n):0)+MOD)%MOD;
    }
};