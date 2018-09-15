class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.empty())
            return {-1,-1};
        int i=0,j=nums.size()-1,mid,start;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(nums[mid]==target&&mid>i&&nums[mid-1]!=target)
                break;
            else if(nums[mid]==target&&mid==i)
                break;
            else if(nums[mid]>target||nums[mid]==target)
                j=mid-1;
            else
                i=mid+1;
        }
        if(nums[mid]!=target)
            return {-1,-1};
        start=mid;
        i=0,j=nums.size()-1;
        while(i<=j)
        {
            mid=(i+j)/2;
            cout<<i<<" "<<j<<endl;
            if(nums[mid]==target&&mid<j&&nums[mid+1]!=target)
                break;
            else if(nums[mid]==target&&mid==j)
                break;
            else if(nums[mid]<target||nums[mid]==target)
                i=mid+1;
            else
                j=mid-1;
        }
        return {start,mid};
    }
};