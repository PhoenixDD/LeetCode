class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int max=nums[0],min=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                max^=min^=max^=min;
            max=std::max(nums[i],nums[i]*max),min=std::min(nums[i],nums[i]*min);
            res=std::max(res,max);
        }
        return res;
    }
};