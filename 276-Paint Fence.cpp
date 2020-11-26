//Either paint same as before or different, if same,we skip next and we have k-1 colors for (i-2)th position else if different we have k-1 colors to make it different for (i-1)th position.
static int memo[1000];
class Solution {
public:
    int k;
    int dp(int n)
    {
        if(n<=0)
            return 0;
        if(n==1)
            return k;
        if(n==2)
            return k*k;
        if(memo[n]!=-1)
            return memo[n];
        return memo[n]=(k-1)*dp(n-1)+(k-1)*dp(n-2);
    }
    int numWays(int n, int k) 
    {
        memset(memo,-1,sizeof memo);
        this->k=k;
        return dp(n);
    }
};