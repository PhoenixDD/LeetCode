class Solution {
public:
    vector<int> memo;
    int dp(int N)
    {
        if(!N)
            return 0;
        if(memo[N]!=-1)
            return memo[N];
        memo[N]=dp(N-1)+1;
        for(int i=0;i<N-2;i++)          //Try copy pasting the result of i: 0..N-3 , N-i-2 times.
            memo[N]=max(memo[N],dp(i)+dp(i)*(N-i-2));
        return memo[N];
    }
    int maxA(int N) 
    {
        memo.resize(N+1,-1);
        return dp(N);
    }
};