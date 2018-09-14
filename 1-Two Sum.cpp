class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> occured(nums.size());
        unordered_map<int,int>::const_iterator it;
        for(int i=0;i<nums.size();i++)
        {
            it=occured.find(target-nums[i]);
            if(it==occured.end())
                occured.insert(pair<int,int>(nums[i],i));
            else
                return {i,it->second};
        }
        return {};
    }
};