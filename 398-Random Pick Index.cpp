class Solution {
public:
    Solution(vector<int> nums) 
    {
        for(int i=0;i<nums.size();i++)
            this->nums[nums[i]].push_back(i);
    }
    
    int pick(int target) 
    {
        return nums[target][rand()%nums[target].size()];
    }
    private:
    unordered_map<int,vector<int>> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */