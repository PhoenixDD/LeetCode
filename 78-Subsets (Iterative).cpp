class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int set;
        for(int i=0;i<1<<nums.size();i++)
        {
            result.push_back({});
            for(int j=0;1<<j<=i;j++)
                if(i&1<<j)
                    result.back().push_back(nums[j]);
        }
        return result;
    }
};