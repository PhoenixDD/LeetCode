class Solution {
public:
    struct trie
    {
        int count=0;
        vector<trie*> children={vector<trie*>(26,NULL)};
    }*Root,*root;
    void add(string &s)
    {
        root=Root;
        for(char &c:s)
        {
            root->count++;
            if(!root->children[c-'a'])
                root->children[c-'a']=new trie();
            root=root->children[c-'a'];
        }
    }
    int getUniPrevInd(string &s)
    {
        root=Root->children[s.front()-'a'];
        int result=1;
        for(int i=1;i<s.length();i++)
        {
            if(root->count==1)
                break;
            root=root->children[s[i]-'a'],result++;
        }
        return result;
    }
    string getAbr(string &s)
    {
        if(s.length()<=3)
            return s;
        return s.front()+to_string(s.length()-2)+s.back();
    }
    vector<string> wordsAbbreviation(vector<string>& dict)
    {
        int index;
        unordered_map<string,vector<int>> groups;
        for(int i=0;i<dict.size();i++)
            groups[getAbr(dict[i])].push_back(i);
        for(auto &p:groups)
        {
            Root=new trie();
            for(int &i:p.second)
                if(dict[i].length()>3)
                    add(dict[i]);
            for(int &i:p.second)
                if(dict[i].length()>3)
                {
                    index=getUniPrevInd(dict[i]);
                    if(dict[i].length()-index>2)
                        dict[i]=dict[i].substr(0,index)+to_string(dict[i].length()-index-1)+dict[i].back();
                }
        }
        return dict;
    }
};