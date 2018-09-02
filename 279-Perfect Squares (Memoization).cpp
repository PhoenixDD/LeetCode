class Solution {
public:
    vector<int> memo;
    int helper(int n)
    {
        if(n<4)
            return n;
        else if(memo[n]!=-1)
            return memo[n];
        int temp=INT_MAX;
        for(int i=1;i*i<=n;i++)
            temp=min(temp,1+helper(n-i*i));
        return memo[n]=temp;
    }
    int numSquares(int n)
    {
        memo.resize(n+1,-1);
        return helper(n);
    }
};