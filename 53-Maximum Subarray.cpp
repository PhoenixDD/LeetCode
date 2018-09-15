class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0,Max=INT_MIN;
        for(int &i:nums)
        {
            sum+=i;
            Max=max(Max,sum);
            sum=sum<0?0:sum;
        }
        return Max;
    }
};