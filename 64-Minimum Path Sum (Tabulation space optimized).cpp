class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        vector<int> memo(grid[0].size());
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0&&j==0)
                    memo[j]=grid[0][0];
                else if(i==0)
                    memo[j]=grid[i][j]+memo[j-1];
                else if(j==0)
                    memo[j]=grid[i][j]+memo[j];
                else
                    memo[j]=grid[i][j]+min(memo[j-1],memo[j]);
            }
        return memo[grid[0].size()-1];
    }
};