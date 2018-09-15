class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 0;
        int max=0,jumps=0,last=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>last)
            {
                jumps++;
                last=max;
            }
            max=std::max(nums[i]+i,max);
        }
        return jumps;
    }
};