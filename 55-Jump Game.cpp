class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(nums.size()==1)
            return true;
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(max<i)
                return false;
            max=std::max(max,nums[i]+i);
            if(max>=nums.size()-1)
                return true;
        }
        return false;
    }
};