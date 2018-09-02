class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int i=1,j=nums.size(),mid,count;
        while(i<=j)
        {
            mid=(i+j)>>1;
            count=0;
            for(int &i:nums)
                if(i<=mid)
                    count++;
            if(count<=mid)
                i=mid+1;
            else
                j=mid-1;
        }
        return i;
    }
};