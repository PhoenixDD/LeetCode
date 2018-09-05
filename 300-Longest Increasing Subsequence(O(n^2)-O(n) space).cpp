class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        int max=1;
        vector<int> memo(nums.size(),1);
        for(int i=1;i<nums.size();i++)
            for(int j=0;j<i;j++)
                if(nums[j]<nums[i]&&memo[i]<memo[j]+1)
                    max=std::max(memo[i]=memo[j]+1,max);
        return max;
    }
};