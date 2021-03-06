class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n,vector<int>(2,0));
        cols.resize(n,vector<int>(2,0));
        this->n=n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        if(row==col&&++fDiag[player-1]==n)
            return player;
        if(row+col==n-1&&++rDiag[player-1]==n)
            return player;
        if(++rows[row][player-1]==n||++cols[col][player-1]==n)
            return player;
        return 0;
    }
    
    private:
    vector<vector<int>> rows,cols;
    vector<int> fDiag{vector<int>(2,0)},rDiag{vector<int>(2,0)};
    int n;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */