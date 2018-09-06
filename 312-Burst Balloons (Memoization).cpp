class Solution {
public:
    vector<vector<int>> memo;
    int maxCoins(vector<int>& nums,int i,int j)
    {
        if(i>j)
            return 0;
        if(memo[i][j]!=INT_MIN)
            return memo[i][j];
        for(int k=i;k<=j;k++)
            memo[i][j]=max(memo[i][j],maxCoins(nums,i,k-1)+(i-1<0?1:nums[i-1])*nums[k]*(j+1>=nums.size()?1:nums[j+1])+maxCoins(nums,k+1,j));
        return memo[i][j];
    }
    int maxCoins(vector<int>& nums) 
    {
        memo.resize(nums.size(),vector<int>(nums.size(),INT_MIN));
        return maxCoins(nums,0,nums.size()-1);
    }
};