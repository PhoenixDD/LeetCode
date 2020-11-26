static vector<int> dirs={-1,0,1,0,-1};
static void hash_combine(size_t& seed,const int& v)
{
    seed^=v+0x9e3779b9+(seed<<6)+(seed>>2);
}
static struct customHash
{
    public:
    size_t operator()(const vector<pair<int,int>> &x) const
    {
        size_t hash = 0;
        for(const pair<int,int> &p:x)
            hash_combine(hash,p.first),hash_combine(hash,p.second);
        return hash;
    }
};
class Solution {
public:
    unordered_set<vector<pair<int,int>>,customHash> uniqueIslands;
    vector<pair<int,int>> landPoints;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        grid[i][j]=0;
        landPoints.push_back({i,j});
        int x,y;
        for(int d=0;d<4;d++)
        {
            x=i+dirs[d],y=j+dirs[d+1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[x].size()&&grid[x][y])
                dfs(grid,x,y);
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                {
                    landPoints.clear();
                    dfs(grid,i,j);
                    for(pair<int,int> &p:landPoints)
                        p.first-=i,p.second-=j;
                    sort(landPoints.begin(),landPoints.end());
                    uniqueIslands.insert(landPoints);
                }
        return uniqueIslands.size();
    }
};