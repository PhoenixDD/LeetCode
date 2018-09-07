class Solution {
public:
    vector<int> sum;
    vector<vector<int>> memo;
    int helper(vector<int>& nums,int parts,int start)
    {
        if(parts==1)
            return memo[parts][start]=sum[nums.size()]-sum[start];
        if(memo[parts][start]!=-1)
            return memo[parts][start];
        int Min=INT_MAX;
        for(int i=start;i<nums.size()-1&&nums.size()-i+1>=parts;i++)
            Min=min(Min,max(helper(nums,parts-1,i+1),sum[i+1]-sum[start]));
        return memo[parts][start]=Min;
    }
    int splitArray(vector<int>& nums, int m) 
    {
        sum.resize(nums.size()+1);
        memo.resize(m+1,vector<int>(nums.size(),-1));
        sum[0]=0;
        for(int i=0;i<nums.size();i++)
            sum[i+1]=sum[i]+nums[i];
        return helper(nums,m,0);
    }
};