class Solution {
public:
    vector<int> memo;
    int numTrees(int n)
    {
        if(n==0||n==1)
            return 1;
        if(memo[n]!=-1)
            return memo[n];
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=numTrees(i)*numTrees(n-i-1);
        return memo[n]=sum;
    }
    Solution()
    {
        memo.resize(100,-1);
    }
};