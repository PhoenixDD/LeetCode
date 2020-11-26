static vector<int> dirs{-1,0,1,0,-1};
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        int m=maze.size(),n=maze.front().size();
        queue<pair<int,int>> q;
        maze[start.front()][start.back()]=2;
        for(int d=0;d<4;d++)
            q.push({start.front()*n+start.back(),d});
        int steps=0,i,j,x,y;
        while(!q.empty())
        {
            for(int size=q.size();size;size--,q.pop())
            {
                i=q.front().first/n,j=q.front().first%n;
                x=i+dirs[q.front().second],y=j+dirs[q.front().second+1];
                if(x<0||y<0||x>=m||y>=n||maze[x][y]==1)
                {
                    if(maze[i][j]!=2)
                    {
                        maze[i][j]=2;
                        if(i==destination.front()&&j==destination.back())
                            return steps;
                        for(int d=0;d<4;d++)
                        {
                            x=i+dirs[d],y=j+dirs[d+1];
                            if(x>=0&&y>=0&&x<m&&y<n&&!maze[x][y])
                                q.push({x*n+y,d});
                        }
                    }
                }
                else
                    q.push({x*n+y,q.front().second});
            }
            steps++;
        }
        return -1;
    }
};