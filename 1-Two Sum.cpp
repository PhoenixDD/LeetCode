class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result(2);
        unordered_map<int,int> matches(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(matches.find(target-nums[i])!=matches.end())
            {
                result[0]=matches[target-nums[i]];
                result[1]=i;
                return result;
            }
            else
                matches[nums[i]]=i;
        }
        
    }
};