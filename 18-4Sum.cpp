class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int &target)
    {
        if(nums.size()<4)
            return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int i,j;
        for(int l=0;l<nums.size()-3;l++)
        {
            if(nums[l]>target&&target>=0)
                return result;
            if(l!=0&&nums[l]==nums[l-1])
                continue;
            for(int k=l+1;k<nums.size()-2;k++)
            {
                if(nums[k]+nums[l]>target&&target>=0)
                    break;
                if(k!=l+1&&nums[k]==nums[k-1])
                    continue;
                i=k+1,j=nums.size()-1;
                while(i<j)
                {
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                    {
                        result.push_back({nums[i],nums[j],nums[k],nums[l]});
                        i++,j--;
                        while(nums[i]==nums[i-1])
                            i++;
                        while(nums[j]==nums[j+1])
                            j--;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]<target)
                        i++;
                    else
                        j--;
                }    
            }
        }
        return result;
    }
};