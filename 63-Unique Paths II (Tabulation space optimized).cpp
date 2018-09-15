class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        vector<int> memo(obstacleGrid[0].size());
        for(int i=0;i<obstacleGrid.size();i++)
            for(int j=0;j<obstacleGrid[0].size();j++)
            {
                if(i==0&&j==0)
                    memo[j]=obstacleGrid[0][0]==0;
                else if(obstacleGrid[i][j]==1)
                    memo[j]=0;
                else if(i==0)
                    memo[j]=memo[j-1];
                else if(j==0)
                    memo[j]=memo[j];
                else
                    memo[j]+=memo[j-1];
            }
        return memo[obstacleGrid[0].size()-1];
    }
};