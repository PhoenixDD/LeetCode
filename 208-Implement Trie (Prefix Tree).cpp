class Trie {
public:
    /** Initialize your data structure here. */
    struct Tray
    {
        bool isleaf;
        vector<Tray*> children{vector<Tray*>(26,NULL)};
        Tray():isleaf(false){};
    }*root,*Root;
    Trie()
    {
        root=new Tray();        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Root=root;
        for(char &i:word)
        {
            if(!Root->children[i-'a'])
                Root->children[i-'a']=new Tray();
            Root=Root->children[i-'a'];
        }
        Root->isleaf=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Root=root;
        for(char &i:word)
            if(!Root->children[i-'a'])
                return false;
            else
                Root=Root->children[i-'a'];
        return Root->isleaf;
                
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Root=root;
        for(char &i:prefix)
            if(!Root->children[i-'a'])
                return false;
            else
                Root=Root->children[i-'a'];
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */