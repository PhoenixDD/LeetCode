class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int cnt;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                cnt=0;
                for(int k=max(i-1,0);k<=min(i+1,(int)board.size()-1);k++)
                    for(int l=max(j-1,0);l<=min(j+1,(int)board[0].size()-1);l++)
                        cnt+=board[k][l]&1;
                cnt-=board[i][j]&1;
                if(board[i][j]&1&&cnt>=2&&cnt<=3)
                    board[i][j]=3;
                else if(!(board[i][j]&1)&&cnt==3)
                    board[i][j]=2;
            }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                board[i][j]>>=1;
    }
};