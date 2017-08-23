class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        if(nums.size()==0)
            return 0;
        int not_val=nums.size()-1,count=0;
        while(not_val>=0&&nums[not_val]==val)
        {
            count++;
            not_val--;
        }
        if(not_val==-1)
            return 0;
        for(int i=0;i<nums.size()&&i<not_val;i++)
        {
            if(nums[i]==val)
            {
                count++;
                nums[i]=nums[not_val];
                not_val--;
                while(nums[not_val]==val&&not_val>i)
                {
                    count++;
                    not_val--;
                }
                if(not_val==i)
                    return nums.size()-count;
            }
        }
        return nums.size()-count;
    }
};