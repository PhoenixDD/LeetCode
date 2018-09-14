class Solution {
public:
    vector<int> dirs={-1,0,1,0,-1};
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int temp=1,next_i,next_j;
        grid[i][j]=0;
        for(int x=0;x<4;x++)
            if((next_i=i+dirs[x])<grid.size()&&(next_j=j+dirs[x+1])<grid[0].size()&&next_i>=0&&next_j>=0&&grid[next_i][next_j]==1)
                temp+=dfs(grid,next_i,next_j);
        return temp;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if(grid.empty()||grid[0].empty())
            return 0;
        int Max=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                    Max=max(Max,dfs(grid,i,j));
        return Max;
    }
};