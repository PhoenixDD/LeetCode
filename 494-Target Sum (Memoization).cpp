class Solution {
public:
    unordered_map<int,unordered_map<int,int>> memo;
    int dp(vector<int> &nums,int i,int S)
    {
        if(i==0&&S==0)
            return 1;
        if(i==0)
            return 0;
        if(memo[i].count(S))
            return memo[i][S];
        return memo[i][S]=dp(nums,i-1,S-nums[i-1])+dp(nums,i-1,S+nums[i-1]);
    }
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        memo.reserve(nums.size());
        return dp(nums,nums.size(),S);
    }
};