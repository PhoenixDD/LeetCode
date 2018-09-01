class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        vector<int> sums(nums.size()+1);
        int sum=0,start,min=INT_MAX;
        for(int i=0;i<=nums.size();i++)
            sums[i]=sum,sum+=nums[i];
        for(int i=1;i<=nums.size();i++)
        {
            if(sums[i]>=s)
            {
                start=upper_bound(sums.begin(),sums.end(),sums[i]-s)-sums.begin();
                min=std::min(min,i-start+1);
            }
        }
        return min==INT_MAX?0:min;
    }
};