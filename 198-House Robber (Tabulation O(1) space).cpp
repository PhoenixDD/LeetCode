class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        else if(nums.size()==1)
            return nums[0];
        int last=max(nums[0],nums[1]),secondlast=nums[0],cur;
        for(int i=2;i<nums.size();i++)
        {
            cur=max(secondlast+nums[i],last);
            secondlast=last;
            last=cur;
        }
        return last;
    }
};