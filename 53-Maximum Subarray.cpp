class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int min=INT_MIN,sum=0,max=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum<0)
                sum=0;
            max=std::max(sum,max);
            if(nums[i]>min)
                min=nums[i];
        }
        if(max)
            return max;
        else
            return min;
    }
};