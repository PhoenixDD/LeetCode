class Solution {
public:
    int part(int i,int j)
    {
        return (i/3)*3+(j/3);
    }
    bool isValid(vector<vector<char>>& board,int i,int j,int val)
    {
        for(int x=0;x<9;x++)
            if(board[i][x]==val+'0'||board[x][j]==val+'0')
                return false;
        
        for(int b=part(i,j)/3*3;b<part(i,j)/3*3+3;b++)
            for(int c=part(i,j)%3*3;c<part(i,j)%3*3+3;c++)
                if(board[b][c]==val+'0')
                    return false;
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board,int i=0,int j=0) 
    {
        if(board[i][j]=='.')
            for(int x=1;x<=9;x++)
            {
                if(isValid(board,i,j,x))
                {
                    board[i][j]=x+'0';
                    if(i==8&&j==8)
                        return true;
                    if(j==8)
                    {
                        if(solveSudoku(board,i+1,0))
                            return true;
                    }
                    else
                    {
                        if(solveSudoku(board,i,j+1))
                            return true;
                    }
                    board[i][j]='.';
                }
            }
        else
        {
            if(i==8&&j==8)
                return true;
            if(j==8)
            {
                if(solveSudoku(board,i+1,0))
                    return true;
            }
            else
            {
                if(solveSudoku(board,i,j+1))
                    return true;
            }
        }
        return false;
    }
};