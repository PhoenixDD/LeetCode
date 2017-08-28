class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<bool> exists_row(board.size()+1),exists_column(board.size()+1);
        for(int i=0;i<board.size();i++)
        {
            fill(exists_row.begin(),exists_row.end(),false);
            fill(exists_column.begin(),exists_column.end(),false);
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(!exists_row[board[i][j]-'0'])
                        exists_row[board[i][j]-'0']=true;
                    else
                        return false;
                }
                if(board[j][i]!='.')
                {
                    if(!exists_column[board[j][i]-'0'])
                        exists_column[board[j][i]-'0']=true;
                    else
                        return false;
                }    
            }
        }
        for(int part=0;part<board.size();part++)
        {
            fill(exists_row.begin(),exists_row.end(),false);
            for(int i=part/3*3;i<part/3*3+3;i++)
                for(int j=part%3*3;j<part%3*3+3;j++)
                    if(board[i][j]!='.')
                        if(!exists_row[board[i][j]-'0'])
                            exists_row[board[i][j]-'0']=true;
                        else
                            return false;
        }
        return true;
    }
};