class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        int i=0,count=0;
        long sum=0;
        while(sum<n)
            if(i<nums.size()&&nums[i]<=sum+1)
                sum+=nums[i++];
            else
                sum+=sum+1,count++;
        return count;
    }
};