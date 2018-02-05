class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int count=0,insert_index=0,same=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                same++;
            else 
                same=1;
            nums[insert_index++]=nums[i];
            count++;
            if(same==2)
                while(nums[i]==nums[i+1])
                    i++;
        }
        return count;
    }
};