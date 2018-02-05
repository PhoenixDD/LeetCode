class Solution {
public:
    vector<vector<int>> memo;
    int recur(vector<vector<int>>& grid,int i,int j)
    {
        if(i==0&&j==0)
            return grid[i][j];
        else if(memo[i][j]!=-1)
            return memo[i][j];
        else if(i==0)
            return memo[i][j]=grid[i][j]+recur(grid,i,j-1);
        else if(j==0)
            return memo[i][j]=grid[i][j]+recur(grid,i-1,j);
        return memo[i][j]=grid[i][j]+min(recur(grid,i-1,j),recur(grid,i,j-1));
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        memo.resize(grid.size(),vector<int>(grid[0].size(),-1));
        return recur(grid,grid.size()-1,grid[0].size()-1);
    }
};