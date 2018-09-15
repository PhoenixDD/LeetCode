class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if(nums.empty())
            return 1;
        int end=nums.size()-1;
        for(int i=0;i<=end;)
            if(nums[i]<=0)
                swap(nums[i],nums[end--]);
            else
                i++;
        for(int i=0;i<=end;i++)
            if(abs(nums[i])-1<=end&&nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        for(int i=0;i<=end;i++)
            if(nums[i]>0)
                return i+1;
        return end+2;
    }
};