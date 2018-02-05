class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void select(int n,int k)
    {
        if(k==0)
        {
            result.push_back(temp);
            return;
        }
        else if(n==0)
            return;
        temp[k-1]=n;
        select(n-1,k-1);
        select(n-1,k);
    }
    vector<vector<int>> combine(int n, int k)
    {
        result.reserve(100000);
        temp.resize(k,0);
        select(n,k);
        return result;
    }
};