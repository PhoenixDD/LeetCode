class Solution {
 public:
    void moveBoard(vector<vector<int>>& board)
    {
        for(int i=board.size()-1;i>=0;i--)
            for(int j=0;j<board[i].size();j++)
                while(board[i][j]<0)
                {
                    int row;
                    for(row=i-1;row>=0&&board[row][j];row--)
                        board[row+1][j]=board[row][j];
                    board[row+1][j]=0;
                }
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    int val;
    bool moved;
    while(true){        
        moved=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j+2<board[i].size();j++){
                val=abs(board[i][j]);
                if(val!=0&&val==abs(board[i][j+1])&&val==abs(board[i][j+2])){
                    board[i][j]=-val;
                    board[i][j+1]=-val;
                    board[i][j+2]=-val;
                    moved=true;
                }
            }
        }
        for(int j=0;j<board[0].size();j++){
            for(int i=0;i+2<board.size();i++){
                val=abs(board[i][j]);
                if(val!=0&&val==abs(board[i+1][j])&&val==abs(board[i+2][j])){
                    board[i][j]=-val;
                    board[i+1][j]=-val;
                    board[i+2][j]=-val;
                    moved=true;
                }
            }
        }
        if(moved)
            moveBoard(board);
        else
            return board;
    };
    return board;
 }
 };