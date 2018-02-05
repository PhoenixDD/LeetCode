// Lomuto partition algorithm
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int i=0,j=0,temp;
        for(int k=0;k<nums.size();k++)
        {
            temp=nums[k];
            nums[k]=2;
            if(temp<2)
                nums[j++]=1;
            if(temp<1)
                nums[i++]=0;
        }
    }
};