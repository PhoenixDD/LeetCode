class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Trie
    {
        bool isleaf;
        vector<Trie*> children{vector<Trie*>(26,NULL)};
        Trie():isleaf(false){};
    }*root,*Root;
    WordDictionary() 
    {
        root=new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        Root=root;
        for(char &i:word)
        {
            if(!Root->children[i-'a'])
                Root->children[i-'a']=new Trie();
            Root=Root->children[i-'a'];
        }
        Root->isleaf=true;
    }
    bool search(string &word,int start,Trie *subRoot)
    {
        if(start==word.length()&&subRoot->isleaf)
            return true;
        else if(start==word.length())
            return false;
        if(word[start]=='.')
        {
            for(int i=0;i<26;i++)
                if(subRoot->children[i]&&search(word,start+1,subRoot->children[i]))
                    return true;
            return false;
        }
        else if(!subRoot->children[word[start]-'a'])
                return false;
        else
            return search(word,start+1,subRoot->children[word[start]-'a']);
        return false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return search(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */