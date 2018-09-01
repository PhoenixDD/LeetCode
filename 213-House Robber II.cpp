class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& nums,int i,bool lasthouse)
    {
        if(i<=0)
            return 0;
        if(i==1)
            return lasthouse?0:nums[i-1];
        if(memo[lasthouse][i]!=-1)
            return memo[lasthouse][i];
        return memo[lasthouse][i]=max(nums[i-1]+dp(nums,i-2,i==nums.size()?true:lasthouse),dp(nums,i-1,lasthouse));
    }
    int rob(vector<int>& nums) 
    {
        memo.resize(2,vector<int>(nums.size()+1,-1));
        return dp(nums,nums.size(),false);
    }
};