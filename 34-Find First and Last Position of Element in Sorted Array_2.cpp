class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.empty())
            return {-1,-1};
        int i=0,j=nums.size()-1,mid;
        while(i<j)
        {
            mid=(i+j)>>1;
            if(nums[mid]>=target)
                j=mid;
            else
                i=mid+1;
        }
        if(nums[i]!=target)
            return {-1,-1};
        int x=i;
        j=nums.size()-1;
        while(i<=j)
        {
            mid=(i+j)>>1;
            if(mid==nums.size()-1||nums[mid]==target&&nums[mid+1]!=target)
               return {x,mid};
            else if(nums[mid]<=target)
                i=mid+1;
            else
                j=mid-1;
        }
        return {x,x};
    }
};