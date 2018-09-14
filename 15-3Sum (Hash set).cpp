class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if(nums.size()<3)
            return {};
        unordered_set<int> s;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]>0)
                break;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            s.clear();
            for(int j=i+1;j<nums.size();j++)
            {
                if(j<nums.size()-1&&nums[j]==nums[j+1])
                {
                    s.insert(nums[i]+nums[j]);
                    if(s.find(-nums[j])!=s.end())
                        result.push_back({nums[i],-nums[i]-nums[j],nums[j]});
                }
                else if(s.find(-nums[j])!=s.end())
                    result.push_back({nums[i],-nums[i]-nums[j],nums[j]});
                else
                    s.insert(nums[i]+nums[j]);
                while(j<nums.size()-1&&nums[j]==nums[j+1])
                    j++;
            }
        }
        return result;
    }
};