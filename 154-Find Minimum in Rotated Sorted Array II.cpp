class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int start=0,end=nums.size()-1,mid;
        while(start<end)
        {
            if(nums[start]<nums[end])
                return nums[start];
            mid=(start+end)/2;
            if(nums[mid]>nums[end])
                start=mid+1;
            else if(nums[start]>nums[mid])
                end=mid;
            else
                end--;
        }
        return nums[start];
    }
};