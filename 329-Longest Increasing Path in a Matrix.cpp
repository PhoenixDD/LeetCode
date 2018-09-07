class Solution {
public:
    vector<vector<int>> memo;
    int dfs(vector<vector<int>>& matrix,int i,int j,int prev)
    {
        if(i>=matrix.size()||i<0||j<0||j>=matrix[0].size()||i>=matrix.size()||matrix[i][j]<=prev)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        return memo[i][j]=1+max({dfs(matrix,i+1,j,matrix[i][j]),dfs(matrix,i,j+1,matrix[i][j]),dfs(matrix,i-1,j,matrix[i][j]),dfs(matrix,i,j-1,matrix[i][j])});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        memo.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        int Max=0;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                Max=max(Max,dfs(matrix,i,j,INT_MIN));
        return Max;
    }
};