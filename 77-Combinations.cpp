class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void helper(int n,int k)
    {
        if(k==0)
        {
            result.push_back(temp);
            return;
        }
        if(n==0)
            return;
        temp.push_back(n);
        helper(n-1,k-1);
        temp.pop_back();
        helper(n-1,k);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        helper(n,k);
        return result;
    }
};