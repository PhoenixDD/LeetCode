class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void helper(int k,int n,int num)
    {
        if(n==0&&k==0)
        {
            result.push_back(temp);
            return;
        }
        if(n==0||k==0||num==0)
            return;
        temp.push_back(num);
        helper(k-1,n-num,num-1);
        temp.pop_back();
        helper(k,n,num-1);
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        helper(k,n,9);
        return result;
    }
};