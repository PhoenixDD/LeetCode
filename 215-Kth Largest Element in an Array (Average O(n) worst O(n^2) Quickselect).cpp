class Solution {
public:
    int part(vector<int>& nums,int i,int j)
    {
        int pivot=j--;
        while(i<=j)
        {
            while(i<=j&&nums[i]<=nums[pivot])i++;
            while(i<=j&&nums[j]>=nums[pivot])j--;
            if(i<j)
                swap(nums[i],nums[j]);
        }
        swap(nums[i],nums[pivot]);
        return i;
    }
    int quickselect(vector<int>& nums,int i,int j,int &k)
    {
        int p=part(nums,i,j);
        if(p==nums.size()-k)
            return nums[p];
        if(p<nums.size()-k)
            return quickselect(nums,p+1,j,k);
        return quickselect(nums,i,p-1,k);
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        return quickselect(nums,0,nums.size()-1,k);
    }
};