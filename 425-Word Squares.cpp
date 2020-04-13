//Trie + BackTrack DFS
class Solution {
public:
    vector<vector<string>> result;
    vector<string> temp;
    struct Trie
    {
        bool isLeaf=false;
        vector<Trie*> children{vector<Trie*>(26,NULL)};
    }*Root,*root;
    void insert(string &s)
    {
        root=Root;
        for(char &c:s)
        {
            if(!root->children[c-'a'])
                root->children[c-'a']=new Trie();
            root=root->children[c-'a'];
        }
        root->isLeaf=true;
    }
    Trie* getIt(int row,int col)
    {
        if(row<0||col>=temp[0].size())
            return Root;
        root=Root;
        int i=0;
        while(i<=row)
            root=root->children[temp[i++][col]-'a'];
        return root;
    }
    void bt(int row,int col,Trie* rowStart,Trie* colStart)
    {
        if(col==temp[0].size()&&row==temp.size())
        {
            result.push_back(temp);
            return;
        }
        if(col==temp[0].size())
        {
            if(rowStart->isLeaf)
            {
                Trie* r=getIt(row,row+1);
                return bt(row+1,row+1,r,r);
            }
        }
        else
            for(int i=0;i<26;i++)
                if(rowStart->children[i]&&colStart->children[i])
                    temp[col][row]=i+'a',temp[row][col]=i+'a',bt(row,col+1,rowStart->children[i],getIt(row-1,col+1));
    }
    vector<vector<string>> wordSquares(vector<string>& words) 
    {
        temp.resize(words[0].size(),string(words[0].size(),'.'));
        Root=new Trie();
        for(string &s:words)
            insert(s);
        bt(0,0,Root,Root);
        return result;
    }
};