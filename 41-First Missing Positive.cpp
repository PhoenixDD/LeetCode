class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        for(int i=j;i<nums.size();i++)
        {
            if(abs(nums[i])+j-1<nums.size()&&nums[abs(nums[i])+j-1]>0)
                nums[abs(nums[i])+j-1]*=-1;
        }
        for(int i=j;i<nums.size();i++)
        {
            if(nums[i]>0)
                return i-j+1;
        }
        return nums.size()-j+1;
    }
};