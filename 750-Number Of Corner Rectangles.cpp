static int memo[201][201];
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) 
    {
        memset(memo,0,sizeof memo);
        int result=0;
        if(grid.size()>grid.front().size())
        {
            for(int k=0;k<grid.size();k++)
                for(int i=0;i<grid[0].size();i++)
                    if(grid[k][i])
                        for(int j=i+1;j<grid[0].size();j++)
                            if(grid[k][j])
                                result+=memo[i][j]++;
        }
        else
        {
            for(int k=0;k<grid[0].size();k++)
                for(int i=0;i<grid.size();i++)
                    if(grid[i][k])
                        for(int j=i+1;j<grid.size();j++)
                            if(grid[j][k])
                                result+=memo[i][j]++;
        }
        return result;
        
    }
};