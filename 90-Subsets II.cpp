class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int last=INT_MIN;
    void recur(vector<int>& nums,int n)
    {
        if(n==nums.size())
        {
            result.push_back(temp);
            return;
        }
        if(last!=nums[n])
        {
            temp.push_back(nums[n]);
            recur(nums,n+1);
            temp.pop_back();
            last=nums[n];
        }
        recur(nums,n+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        recur(nums,0);
        return result;
    }
};