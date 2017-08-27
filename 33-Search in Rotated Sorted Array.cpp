class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if(nums.empty())
            return -1;
        int i=0,j=nums.size()-1,mid;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(mid>i&&mid<j&&nums[mid-1]>nums[mid]&&nums[mid+1]>nums[mid])
                break;
            else if(mid==i&&mid<j&&nums[mid]>nums[mid+1])
            {
                mid=j;
                break;
            }
            else if(mid==j&&mid>i&&nums[mid]<nums[mid-1])
                break;
            if(nums[i]>nums[mid])
                j=mid-1;
            else if(nums[j]<nums[mid])
                i=mid+1;
            else
            {
                mid=i;
                break;
            }
        }
        int pos;
        if(mid==0)
        {
            pos=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(nums[pos]==target)
                return pos;
            else
                return -1;
        }
        else
        {
            pos=lower_bound(nums.begin(),nums.begin()+mid-1,target)-nums.begin();
            if(nums[pos]==target)
                return pos;
            else
            {
                pos=lower_bound(nums.begin()+mid,nums.end(),target)-nums.begin();
                if(nums[pos]==target)
                    return pos;
                else
                    return -1;
            }
        }
    }
};