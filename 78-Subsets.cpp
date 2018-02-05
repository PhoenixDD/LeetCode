class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> temp;
        vector<vector<int>> result;
        result.reserve(pow(2,nums.size()));
        temp.reserve(nums.size());
        for(int i=0;i<pow(2,nums.size());i++)
        {
            temp.clear();
            for(int j=0;j<nums.size();j++)
                if(i&1<<j)
                    temp.push_back(nums[j]);
            result.push_back(temp);
        }
        return result;
    }
};