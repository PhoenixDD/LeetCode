class Solution {
public:
    vector<vector<int>> result;
    void perm(int start,vector<int> &nums)
    {
        if(start==nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[start],nums[i]);
            perm(start+1,nums);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        if(nums.empty())
            return result;
        perm(0,nums);
        return result;
    }
};