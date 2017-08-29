class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void Recur(vector<int>& candidates,int target,int n)
    {
        if(target==0)
        {
            result.push_back(temp);
            return;
        }
        if(n==0||target<0)
            return;
        temp.push_back(candidates[n-1]);
        Recur(candidates,target-candidates[n-1],n);
        temp.pop_back();
        Recur(candidates,target,n-1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target)
    {
        Recur(candidates,target,candidates.size());
        return result;
    }
};