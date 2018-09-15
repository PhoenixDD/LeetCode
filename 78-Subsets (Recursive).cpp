class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void subsets(vector<int>& nums,int i)
    {
        if(i==0)
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i-1]);
        subsets(nums,i-1);
        temp.pop_back();
        subsets(nums,i-1);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        subsets(nums,nums.size());
        return result;
    }
};