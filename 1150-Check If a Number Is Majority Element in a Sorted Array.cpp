//log(n)
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) 
    {
        if(nums[nums.size()/2]!=target)
            return false;
        int j=nums.size()-1,i=0,mid,start;
        while(i<j)                          //simulate lower_bound
        {
            mid=(i+j)>>1;
            if(nums[mid]>=target)
                j=mid;
            else
                i=mid+1;
        }
        start=i;
        i=start,j=nums.size()-1;
        while(i<j)                          //Simulate upper_bound
        {
            mid=(i+j)>>1;
            if(nums[mid]<=target)
                i=mid+1;
            else
                j=mid;
        }
        return (i==nums.size()-1?1:0)+i-start>nums.size()/2;
    }
};