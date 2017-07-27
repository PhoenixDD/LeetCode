class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        vector<int> temp(3);
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size()-2;k++)
        {
            if(nums[k]>0)
                break;
            if(k!=0&nums[k]==nums[k-1])
                continue;
            int i=k+1,j=nums.size()-1;
            while(i<j)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    
                    temp[0]=nums[i];temp[1]=nums[j];temp[2]=nums[k];
                    result.push_back(temp);
                    i++;j--;
                    while(i<j&&nums[j]==nums[j+1])
                      j--;
                    while(i<j&&nums[i]==nums[i-1])
                      i++;
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