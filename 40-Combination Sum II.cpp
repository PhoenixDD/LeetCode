class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int last=-1;
    void Recur(vector<int>& candidates,int target,int n)
    {
        if(target==0)
        {
            result.push_back(temp);
            return;
        }
        if(n<=0||target<0)
            return;
        if(last!=candidates[n-1])
        {
            temp.push_back(candidates[n-1]);
            Recur(candidates,target-candidates[n-1],n-1);
            last=candidates[n-1];
            temp.pop_back();
        }
        Recur(candidates,target,n-1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        Recur(candidates,target,candidates.size());
        return result;
    }
};