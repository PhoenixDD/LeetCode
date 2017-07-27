class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int difference=INT_MAX,sum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==target)
                    return target;
                else if(abs(nums[i]+nums[j]+nums[k]-target)<difference)
                {
                    difference=abs(nums[i]+nums[j]+nums[k]-target);
                    sum=nums[i]+nums[j]+nums[k];
                }
                if(nums[i]+nums[j]+nums[k]<target)
                    j++;
                else
                    k--;
            }
        }
        return sum;
    }
};