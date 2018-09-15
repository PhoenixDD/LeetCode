class Solution {
public:
    vector<vector<string>> result;
    vector<string> temp;
    vector<int> col;
    bool valid(int r,int c)
    {
        for(int i=0;i<r;i++)
            if(col[i]==c||abs(col[i]-c)==abs(i-r))
                return false;
        return true;
    }
    void solve(int r)
    {
        if(r==temp.size())
        {
            result.push_back(temp);
            return;
        }
        for(int c=0;c<temp.size();c++)
        {
            if(valid(r,c))
            {
                col[r]=c;
                temp[r][c]='Q';
                solve(r+1);
                temp[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        temp.resize(n,string(n,'.'));
        col.resize(n);
        solve(0);
        return result;
    }
};