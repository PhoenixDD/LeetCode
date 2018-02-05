class Solution {
public:
    bool DFS(vector<vector<char>>& board,string& word,int i,int j,int c)
    {
        if(c==word.length())
            return true;
        if(c>word.length()||i<0||j<0||i>=board.size()||j>=board[0].size()||word[c]!=board[i][j])
            return false;
        board[i][j]^=128;
        if(DFS(board,word,i,j+1,c+1)||DFS(board,word,i+1,j,c+1)||DFS(board,word,i-1,j,c+1)||DFS(board,word,i,j-1,c+1))
            return true;
        board[i][j]^=128;
        return false;
            
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(DFS(board,word,i,j,0))
                    return true;
        return false;
    }
};