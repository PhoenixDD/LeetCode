class Solution {
public:
    struct Trie
    {
        string word;
        vector<Trie*> children{vector<Trie*>(26,NULL)};
        Trie():word(""){};
    }*root,*Root;    
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Root=root;
        for(char &i:word)
        {
            if(!Root->children[i-'a'])
                Root->children[i-'a']=new Trie();
            Root=Root->children[i-'a'];
        }
        Root->word=word;
    }
    
    /** Returns if the word is in the trie. */
    vector<int> dirs={-1,0,1,0,-1};
    vector<string> result;
    void dfs(vector<vector<char>>& board,int i,int j,Trie *root)
    {
        if(board[i][j]=='#'||!root->children[board[i][j]-'a'])
            return;
        root=root->children[board[i][j]-'a'];
        if(root->word!="")
            result.push_back(root->word),root->word="";
        char c=board[i][j];
        board[i][j]='#';
        for(int dir=0;dir<4;dir++)
            if(i+dirs[dir]>=0&&j+dirs[dir+1]>=0&&i+dirs[dir]<board.size()&&j+dirs[dir+1]<board[0].size())
                dfs(board,i+dirs[dir],j+dirs[dir+1],root);
        board[i][j]=c;
                
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        root=new Trie();
        for(string &word:words)
            insert(word);
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board,i,j,root);
        return result;
    }
};