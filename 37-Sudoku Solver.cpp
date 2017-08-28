class Solution {
public:
    bool valid(vector<vector<char>>& board,int i,int j,int num)
    {
        for(int k=0;k<board.size();k++)
        {
            if(board[i][k]!='.'&&board[i][k]-'0'==num)
                return false;
            if(board[k][j]!='.'&&board[k][j]-'0'==num)
                return false;
        }
        int part;
        if(i/3==0&&j/3==0)
            part=0;
        else if(i/3==0&&j/3==1)
            part=1;
        else if(i/3==0&&j/3==2)
            part=2;
        else if(i/3==1&&j/3==0)
            part=3;
        else if(i/3==1&&j/3==1)
            part=4;
        else if(i/3==1&&j/3==2)
            part=5;
        else if(i/3==2&&j/3==0)
            part=6;
        else if(i/3==2&&j/3==1)
            part=7;
        else
            part=8;
        for(int m=part/3*3;m<part/3*3+3;m++)
            for(int n=part%3*3;n<part%3*3+3;n++)
                if(board[m][n]!='.'&&board[m][n]-'0'==num)
                    return false;
        return true;
    }
    bool Solve(vector<vector<char>>& board,int i,int j)
    {
        if(board[i][j]=='.')
        {
            for(int num=1;num<=board.size();num++)
            {
                if(valid(board,i,j,num))
                {
                    board[i][j]=num+'0';
                    if(j==8&&i==8)
                        return true;
                    else if(j<8)
                    {
                        if(Solve(board,i,j+1))
                            return true;
                    }
                    else if(j==8)
                    {
                        if(Solve(board,i+1,0))
                            return true;
                    }
                    board[i][j]='.';
                }
            }
        }
        else
        {
            if(j==8&&i==8)
                return true;
            else if(j<8)
            {
                if(Solve(board,i,j+1))
                    return true;
            }
            else if(j==8)
            {
                if(Solve(board,i+1,0))
                        return true;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        Solve(board,0,0);
    }
};