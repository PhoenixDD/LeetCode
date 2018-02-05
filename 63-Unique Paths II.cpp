class Solution {
public:
    vector<vector<int>> memo;
    int recur(int m, int n,vector<vector<int>>& obstacleGrid)
    {
        if(m<0||n<0||obstacleGrid[m][n]==1)
            return 0;
        else if(m==0&&n==0)
            return 1;
        else if(memo[m][n]!=-1)
            return memo[m][n];
        return memo[m][n]=recur(m-1,n,obstacleGrid)+recur(m,n-1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if(obstacleGrid.size()==1||obstacleGrid[0].size()==1)
        {
            for(auto &i:obstacleGrid)
                for(int &j:i)
                    if(j==1)
                        return 0;
            return 1;
        }
        memo.resize(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return recur(obstacleGrid.size()-1,obstacleGrid[0].size()-1,obstacleGrid);
    }
};