class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target,int i)
    {
        if(target==0&&i==0)
            return {{}};
        if(i==0||target<0)
            return {};
        vector<vector<int>> result;
        vector<vector<int>> with=combinationSum(candidates,target-candidates[i-1],i);
        vector<vector<int>> without=combinationSum(candidates,target,i-1);
        for(vector<int> &w:with)
            result.push_back(w),result.back().push_back(candidates[i-1]);
        for(vector<int> &w:without)
            result.push_back(w);
        return result;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        return combinationSum(candidates,target,candidates.size());
    }
};