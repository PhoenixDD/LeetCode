class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) 
    {
        if(grid.empty()||grid[0].empty())
            return 0;
        vector<vector<int>> up(grid.size(),vector<int>(grid[0].size(),0)),down(grid.size(),vector<int>(grid[0].size(),0)),left(grid.size(),vector<int>(grid[0].size(),0)),right(grid.size(),vector<int>(grid[0].size(),0));
        int result=0;
        for(int j=0;j<grid[0].size();j++)
            for(int i=1;i<grid.size();i++)
                if(grid[i][j]=='W')
                    up[i][j]=0;
                else
                    up[i][j]=up[i-1][j]+(grid[i-1][j]=='E');
        for(int j=0;j<grid[0].size();j++)
            for(int i=grid.size()-2;i>=0;i--)
                if(grid[i][j]=='W')
                    down[i][j]=0;
                else
                    down[i][j]=down[i+1][j]+(grid[i+1][j]=='E');
        for(int i=0;i<grid.size();i++)
            for(int j=1;j<grid[0].size();j++)
                if(grid[i][j]=='W')
                    left[i][j]=0;
                else
                    left[i][j]=left[i][j-1]+(grid[i][j-1]=='E');
        for(int i=0;i<grid.size();i++)
            for(int j=grid[0].size()-2;j>=0;j--)
                if(grid[i][j]=='W')
                    right[i][j]=0;
                else
                    right[i][j]=right[i][j+1]+(grid[i][j+1]=='E');
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='0')
                    result=max(result,up[i][j]+down[i][j]+left[i][j]+right[i][j]);
        return result;
    }
};