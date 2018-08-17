//Union-Find Solution
class Solution {
public:
    vector<int> parent,Rank;
    int Find(int x)
    {
        return parent[x]==x?x:parent[x]=Find(parent[x]);
    }
    void Union(int x,int y)
    {
        int xset=Find(x),yset=Find(y);
        if(xset!=yset)
        {
            Rank[xset]<Rank[yset]?parent[xset]=yset:parent[yset]=xset;
            if(Rank[xset]==Rank[yset])
                Rank[xset]++;
        }
    }
    void solve(vector<vector<char>>& board)
    {
        if(board.empty())
            return;
        parent.resize(board.size()*board[0].size()+1,0);
        Rank.resize(board.size()*board[0].size()+1,0);
        for(int i=0;i<=board.size()*board[0].size();i++)
            parent[i]=i;
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]=='O')
                Union(i,board.size()*board[0].size());
            if(board[board.size()-1][i]=='O')
                Union((board.size()-1)*board[0].size()+i,board.size()*board[0].size());
        }
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')
                Union(i*board[0].size(),board.size()*board[0].size());
            if(board[i][board[0].size()-1]=='O')
                Union(i*board[0].size()+board[0].size()-1,board.size()*board[0].size());
        }
        for(int i=1;i<board.size()-1;i++)
            for(int j=1;j<board[0].size()-1;j++)
            {
                if(board[i][j]=='O')
                {
                    if(i-1>=0&&board[i-1][j]=='O')
                        Union(i*board[0].size()+j,(i-1)*board[0].size()+j);
                    if(j-1>=0&&board[i][j-1]=='O')
                        Union(i*board[0].size()+j,i*board[0].size()+j-1);
                    if(i+1<board.size()&&board[i+1][j]=='O')
                        Union(i*board[0].size()+j,(i+1)*board[0].size()+j);
                    if(j+1<board[0].size()&&board[i][j+1]=='O')
                        Union(i*board[0].size()+j,i*board[0].size()+j+1);
                }
                    
            }
        for(int i=1;i<board.size()-1;i++)
            for(int j=1;j<board[0].size()-1;j++)
                if(Find(i*board[0].size()+j)!=Find(board.size()*board[0].size()))
                    board[i][j]='X';
    }
};