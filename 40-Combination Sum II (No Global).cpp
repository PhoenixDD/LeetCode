class Solution {
public:
    int last=-1;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target,int i)
    {
        if(target==0&&i==0)
            return {{}};
        if(i==0||target<0)
            return {};
        vector<vector<int>> result;
        if(last!=candidates[i-1])
        {
            vector<vector<int>> with=combinationSum2(candidates,target-candidates[i-1],i-1);
            last=candidates[i-1];
            for(vector<int> &w:with)
                result.push_back(w),result.back().push_back(candidates[i-1]);
        }
        vector<vector<int>> without=combinationSum2(candidates,target,i-1);
        for(vector<int> &w:without)
            result.push_back(w);
        return result;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        return combinationSum2(candidates,target,candidates.size());
    }
};