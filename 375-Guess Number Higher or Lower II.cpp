//Same as the egg drop problem
class Solution {
public:
    vector<vector<int>> memo;
    int dp(int i,int j)
    {
        if(i>=j)
            return 0;
        if(memo[i][j]!=INT_MAX)
            return memo[i][j];
        for(int x=i;x<=j;x++)
            memo[i][j]=min(memo[i][j],x+max(dp(x+1,j),dp(i,x-1)));
        return memo[i][j];
    }
    int getMoneyAmount(int n) 
    {
        memo.resize(n,vector<int>(n+1,INT_MAX));
        return dp(1,n);
    }
};