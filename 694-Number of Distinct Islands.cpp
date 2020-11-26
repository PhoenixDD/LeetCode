//Utilize the fact that the path signature for same island remains same as we start from top left.
static vector<int> dirs={-1,0,1,0,-1};
class Solution {
public:
    unordered_set<string> uniqueIslands;
    string path;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        grid[i][j]=0;
        int x,y;
        for(int d=0;d<4;d++)
        {
            x=i+dirs[d],y=j+dirs[d+1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[x].size()&&grid[x][y])
                path+=d+'0',dfs(grid,x,y);
        }
        path+='4';
    }
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                {
                    path="";
                    dfs(grid,i,j);
                    uniqueIslands.insert(path);
                }
        return uniqueIslands.size();
    }
};