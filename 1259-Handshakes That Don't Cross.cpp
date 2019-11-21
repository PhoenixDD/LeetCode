static unordered_map<int,int> memo;
static int MOD=1e9+7;
class Solution {
public:
    static int dp(int n)
    {
        if(n<=2)
            return 1;
        if(memo.count(n))
            return memo[n];
        long result=0;
        int last=n/2+1;
        for(int i=2;i<=n/2;i+=2)
            result+=(2*(long)dp(n-i)*dp(i-2))%MOD;
        if(last%2==0)
            result+=(long)dp(n-last)*dp(last-2);
        return memo[n]=result%MOD;
    }
    int numberOfWays(int num_people) 
    {
        return dp(num_people);
    }
};