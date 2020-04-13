static string sentence;
static vector<int> temp;
static vector<string> result;
class AutocompleteSystem {
public:
    struct Trie
    {
        int index=-1;
        vector<Trie*> children{vector<Trie*>(128,NULL)};
    }*Root,*root;
    vector<int> t;
    vector<string> s;
    function<bool(int &,int &)> cmp=[&](int &l,int &r){return t[l]!=t[r]?t[l]>t[r]:s[l]<s[r];};
    void insert(string &s,int &idx)
    {
        root=Root;
        for(char &c:s)
        {
            if(!root->children[c])
                root->children[c]=new Trie();
            root=root->children[c];
        }
        root->index=idx;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
        Root=new Trie();
        for(int i=0;i<sentences.size();i++)
            insert(sentences[i],i);
        root=Root;
        t=times,s=sentences;
        sentence="";
    }
    void getAllSuffixes(Trie* rootTemp)
    {
        if(rootTemp->index!=-1)
            temp.push_back(rootTemp->index);
        for(int i=0;i<128;i++)
            if(rootTemp->children[i])
                getAllSuffixes(rootTemp->children[i]);
    }
    vector<string> input(char c) 
    {
        if(c=='#')
        {
            if(root->index==-1)
                root->index=s.size(),s.push_back(sentence),t.push_back(1);
            else
                t[root->index]++;
            root=Root;
            sentence="";
            return {};
        }
        if(!root->children[c])
            root->children[c]=new Trie();
        root=root->children[c];
        sentence+=c;
        temp.clear();
        getAllSuffixes(root);
        result.clear();
        int i=0;
        sort(temp.begin(),temp.end(),cmp);
        while(i<temp.size()&&result.size()<3)
            result.push_back(s[temp[i++]]);
        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */