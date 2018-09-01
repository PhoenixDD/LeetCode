class Solution {
public:
    vector<int> dirs={-1,0,1,0,-1};
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='x';
        for(int pos=0,x=i+dirs[pos],y=j+dirs[pos+1];pos<4;pos++,x=i+dirs[pos],y=j+dirs[pos+1])
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]=='1')
                dfs(grid,x,y);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int count=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1')
                    dfs(grid,i,j),count++;
        return count;
    }
};