class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int last=INT_MIN;
    void dup_sub(vector<int> &nums,int i)
    {
        if(!i)
        {
            result.push_back(temp);
            return;
        }
        if(last!=nums[i-1])
        {
            temp.push_back(nums[i-1]);
            dup_sub(nums,i-1);
            temp.pop_back();
            last=nums[i-1];
        }
        dup_sub(nums,i-1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        dup_sub(nums,nums.size());
        return result;
    }
};