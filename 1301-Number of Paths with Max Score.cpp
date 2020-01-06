static int MOD=1e9+7;
class Solution {
public:
    vector<vector<pair<int,int>>> memo;
    vector<int> dirs={-1,0,-1,-1};
    pair<int,int> dp(vector<string>& board,int i,int j)
    {
        if(i==0&&j==0)
            return {0,1};
        if(memo[i][j].first!=-1&&memo[i][j].second!=-1)
            return memo[i][j];
        pair<int,int> temp={0,0};
        memo[i][j]={0,0};
        int x,y;
        for(int d=0;d<3;d++)
        {
            x=i+dirs[d],y=j+dirs[d+1];
            if(x>=0&&y>=0&&board[x][y]!='X')
            {
                temp=dp(board,x,y);
                if(temp.second!=0&&temp.first>memo[i][j].first)
                    memo[i][j]=temp;
                else if(temp.first==memo[i][j].first)
                    memo[i][j].second=(memo[i][j].second+temp.second)%MOD;
            }
        }
        if(memo[i][j].second)
            memo[i][j].first=(memo[i][j].first+(isdigit(board[i][j])?board[i][j]-'0':0))%MOD;
        return memo[i][j];
    }
    vector<int> pathsWithMaxScore(vector<string>& board) 
    {
        memo.resize(board.size(),vector<pair<int,int>>(board[0].size(),pair<int,int>{-1,-1}));
        pair<int,int> result=dp(board,board.size()-1,board[0].size()-1);
        return {result.first,result.second};
    }
};