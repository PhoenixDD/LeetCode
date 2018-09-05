class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int start=0;
        for(int &i:nums)
            if(i>nums[start])
                nums[++start]=i;
            else if(i<nums[start])
                nums[lower_bound(nums.begin(),nums.begin()+start,i)-nums.begin()]=i;
        return nums.empty()?0:start+1;
    }
};