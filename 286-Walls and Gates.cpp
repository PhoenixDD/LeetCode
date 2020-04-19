static vector<int> dirs={-1,0,1,0,-1};
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        queue<int> q;
        int steps=0;
        for(int i=0;i<rooms.size();i++)
            for(int j=0;j<rooms[i].size();j++)
                if(!rooms[i][j])
                    q.push(i*rooms[i].size()+j);
        int row,col,nRow,nCol;
        while(!q.empty())
        {
            for(int size=q.size();size;size--,q.pop())
            {
                row=q.front()/rooms[0].size(),col=q.front()%rooms[0].size();
                if(steps==0||rooms[row][col]==2147483647)
                {
                    rooms[row][col]=steps;
                    for(int d=0;d<4;d++)
                    {
                        nRow=row+dirs[d],nCol=col+dirs[d+1];
                        if(nRow>=0&&nCol>=0&&nRow<rooms.size()&&nCol<rooms[nRow].size()&&rooms[nRow][nCol]==2147483647)
                            q.push(nRow*rooms[0].size()+nCol);
                    }
                }
            }
            steps++;
        }
    }
};