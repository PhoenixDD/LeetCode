class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int sum=0,min_len=INT_MAX,begin=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=s)
                min_len=min(min_len,i-begin+1),sum-=nums[begin++];
        }
        return min_len==INT_MAX?0:min_len;
    }
};