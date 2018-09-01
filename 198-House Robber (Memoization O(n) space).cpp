class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums,int i)
    {
        if(i<=0)
            return 0;
        else if(memo[i]!=-1)
            return memo[i];
        return memo[i]=max(nums[i-1]+rob(nums,i-2),rob(nums,i-1));
    }
    int rob(vector<int>& nums)
    {
        memo.resize(nums.size()+1,-1);
        return rob(nums,nums.size());
    }
};