//Since the numbers are sorted we only need to consider dividing the numbers that are equal into K group
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) 
    {
        int Max=1,count=1;
        for(int i=1;i<nums.size();i++)
        {
            count=nums[i-1]==nums[i]?count+1:1;
            Max=max(count,Max);
        }
        return nums.size()>=Max*K;
    }
};