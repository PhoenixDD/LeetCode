class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                for(int j=nums.size()-1;i>=0;j--)
                    if(nums[j]>nums[i])
                    {
                        swap(nums[j],nums[i]);
                        break;
                    }
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};