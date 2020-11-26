//Can be improved by priority queue on distance and string path.
static vector<tuple<int,int,char>> dirs={{-1,0,'u'},{0,1,'r'},{1,0,'d'},{0,-1,'l'}};
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole)
    {
        vector<string> result;
        int m=maze.size(),n=maze[0].size(),x,y,i,j;
        bool found=false;
        queue<tuple<int,int,string>> q;
        maze[ball.front()][ball.back()]=2;
        for(int d=0;d<4;d++)
            q.push({ball.front()*n+ball.back(),d,string(1,get<2>(dirs[d]))});
        int marker=3;
        while(!q.empty()&&!found)
        {
            for(int size=q.size();size;size--,q.pop())
            {
                i=get<0>(q.front())/n,j=get<0>(q.front())%n;
                if(i==hole.front()&&j==hole.back())
                    found=true,result.push_back(get<2>(q.front()));
                x=i+get<0>(dirs[get<1>(q.front())]),y=j+get<1>(dirs[get<1>(q.front())]);
                if(x<0||y<0||x>=m||y>=n||maze[x][y]==1)
                {
                    if(maze[i][j]==0||maze[i][j]==marker)
                    {
                        maze[i][j]=marker;
                        for(int d=0;d<4;d++)
                        {
                            x=i+get<0>(dirs[d]),y=j+get<1>(dirs[d]);
                            if(x>=0&&y>=0&&x<m&&y<n&&!maze[x][y])
                                q.push({x*n+y,d,get<2>(q.front())+get<2>(dirs[d])});
                        }
                    }
                }
                else
                    q.push({x*n+y,get<1>(q.front()),get<2>(q.front())});
            }
            marker++;
        }
        if(result.empty())
            return "impossible";
        sort(result.begin(),result.end());
        return result.front();
    }
};