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
        memo[n][k]=0;
        for(int i=0;i<min(n,k+1);i++)
            memo[n][k]+=dp(n-1,k-i)%MOD,memo[n][k]%=MOD;
        return memo[n][k];
    }
    int kInversePairs(int n, int k) 
    {
        memo.resize(n+1,vector<int>(k+1,-1));
        return dp(n,k);
    }
};