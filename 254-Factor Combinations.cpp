class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void bt(int n,int s)
    {
        if(n==1)
            return;
        for(int i=s;i<=sqrt(n);i++)
            if(n%i==0)
            {
                temp.push_back(i);
                bt(n/i,i);
                temp.pop_back();
            }
        if(!temp.empty())
        {
            temp.push_back(n);
            result.push_back(temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> getFactors(int n) 
    {
        bt(n,2);
        return result;
    }
};