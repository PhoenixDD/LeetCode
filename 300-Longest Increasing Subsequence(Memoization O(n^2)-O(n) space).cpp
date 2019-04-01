//Recursive LIS (DFS)
class Solution {
public:
    vector<int> memo;
    int dp(vector<int>& nums,int i)
    {
        if(memo[i]!=0)
            return memo[i];
        int Max=0,prev=i==0?INT_MIN:nums[i-1];
        for(int j=i;j<nums.size();j++)
            if(nums[j]>prev)
                Max=max(dp(nums,j+1)+1,Max);
        return memo[i]=Max;
    }
    int lengthOfLIS(vector<int>& nums)
    {
        memo.resize(nums.size()+1,0);
        return dp(nums,0);
    }
};