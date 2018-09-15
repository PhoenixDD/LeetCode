class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int start=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i<nums.size()-2&&nums[i]==nums[i+1]&&nums[i]==nums[i+2])
                while(i<nums.size()-2&&nums[i+1]==nums[i+2])
                    i++;
            if(i<nums.size())
                nums[start++]=nums[i];
        }
        return start;
    }
};