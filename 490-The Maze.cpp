static vector<int> dirs={-1,0,1,0,-1};
class Solution {
public:
    vector<vector<bool>> visited;
    int dstX,dstY;
    bool dfs(vector<vector<int>>& maze,int i,int j)
    {
        if(dstX==i&&dstY==j)
            return true;
        visited[i][j]=true;
        int x,y;
        for(int d=0;d<4;d++)
        {
            x=i,y=j;
            while(x+dirs[d]>=0&&y+dirs[d+1]>=0&&x+dirs[d]<maze.size()&&y+dirs[d+1]<maze[0].size()&&maze[x+dirs[d]][y+dirs[d+1]]==0)
                x+=dirs[d],y+=dirs[d+1];
            if(!visited[x][y]&&dfs(maze,x,y))
                return true;
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        visited.resize(maze.size(),vector<bool>(maze[0].size(),false));
        dstX=destination.front(),dstY=destination.back();
        return dfs(maze,start.front(),start.back());
    }
};