//The median point will be the closest of cluster of points, we find median points of 2Ds row and columns and add the distances since its 2D
class Solution {
public:
    int helper(vector<int> vec,int o)
    {
        int distance=0;
        for(int &i:vec)
            distance+=abs(o-i);
        return distance;
    }
    int minTotalDistance(vector<vector<int>>& grid)
    {
        vector<int> row,col;
        for(int i=0;i<grid.size();i++)
            for(int &j:grid[i])
                if(j)
                    row.push_back(i);
        for(int j=0;j<grid[0].size();j++)
            for(int i=0;i<grid.size();i++)
                if(grid[i][j])
                    col.push_back(j);
        return helper(row,row[row.size()/2])+helper(col,col[col.size()/2]);
    }
};