class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.empty())
            return {};
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size()-2;k++)
        {
            if(nums[k]>0)
                break;
            if(k>0&&nums[k]==nums[k-1])
                continue;
            int i=k+1,j=nums.size()-1;
            while(i<j)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(nums[i]==nums[i+1])
                        i++;
                    while(nums[j]==nums[j-1])
                        j--;
                    i++,j--;
                }
                else if(nums[i]+nums[j]+nums[k]<0)
                    i++;
                else
                    j--;
            }
        }
        return result;
    }
};