class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size()==0)
            return 0;
        int count=0,start=0;
        for(int i=0;i<nums.size();i++)
        {
            nums[start]=nums[i];
            count++;
            start++;
            while(i<nums.size()-1&&nums[i]==nums[i+1])
                i++;
        }
        return count;
    }
};