//Dutch national flag
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int i=0,j=nums.size()-1,k=0;
        while(i<=j)
        {
            if(nums[i]==0)
                swap(nums[k++],nums[i++]);
            else if(nums[i]==2)
                swap(nums[j--],nums[i]);
            else
                i++;
        }
    }
};