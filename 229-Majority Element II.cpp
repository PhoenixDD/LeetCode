class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        if(nums.empty())
            return {};
        int majority1=nums[0],majority2=nums[0],count1=0,count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==majority1)
                count1++;
            else if(nums[i]==majority2)
                count2++;
            else if(!count1)
                majority1=nums[i],count1++;
            else if(!count2)
                majority2=nums[i],count2++;
            else
                count1--,count2--;
        }
        count1=0;count2=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==majority1)
                count1++;
            else if(nums[i]==majority2)
                count2++;
        if(count1>nums.size()/3&&count2>nums.size()/3)
            return {majority1,majority2};
        else if(count1>nums.size()/3)
            return {majority1};
        else if(count2>nums.size()/3)
            return {majority2};
        return {};
    }
};