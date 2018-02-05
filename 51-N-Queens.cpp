class Solution {
public:
    int N;
    vector<vector<string>> result;
    vector<string> temp;
    vector<int> col;
    bool isvalid(int r,int c)
    {
        for(int i=0;i<r;i++)
            if(col[i]==c||abs(col[i]-c)==abs(i-r))
                return false;
        return true;
    }
    void backtrack(int r)
    {
        if(r==N)
        {
            for(int i=N-1;i>=0;i--)
            {
                temp[i]=string(N,'.');
                temp[i][col[i]]='Q';
            }
            result.push_back(temp);
            return;
        }
        for(int c=0;c<N;c++)
            if(isvalid(r,c))
                col[r]=c,backtrack(r+1);
    }
    vector<vector<string>> solveNQueens(int n)
    {
        N=n;
        col.resize(n,0);
        temp.resize(n);
        backtrack(0);
        return result;
    }
};