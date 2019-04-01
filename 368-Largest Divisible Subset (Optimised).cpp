//Recursive LIS solution
class Solution {
public:
    unordered_map<int,vector<int>> memo;
    vector<int> dp(vector<int>& nums,int i)
    {
        if(memo.count(i))
            return memo[i];
        int div=i==0?1:nums[i-1];
        vector<int> Max;
        for(int j=i;j<nums.size();j++)
            if(nums[j]%div==0)
            {
                vector<int> temp=dp(nums,j+1);
                if(Max.size()<temp.size()+1)
                    swap(Max,temp),Max.push_back(nums[j]);
            }
        return memo[i]=Max;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        return dp(nums,0);
    }
};