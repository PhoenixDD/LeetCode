class Solution {
public:
    struct node
    {
        string word;
        node *parent;
        node(string &w,node* p=NULL):word(w),parent(p){}
    };
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        bool done=false;
        int size;
        vector<vector<string>> result;
        vector<string> res;
        vector<string> to_del;
        node *temp;
        char letter;
        unordered_set<string> dict;
        for(string &s:wordList)
            dict.insert(s);
        if(dict.find(endWord)==dict.end())
            return {};
        queue<node*> q;
        q.push(new node(endWord));
        dict.erase(endWord);
        while(!q.empty())
        {
            size=q.size();
            while(size--)
            {
                for(char &c:q.front()->word)
                {
                    letter=c;
                    for(int i=0;i<26;i++)
                    {
                        c='a'+i;
                        if(q.front()->word==beginWord)
                        {
                            done=true;
                            res.clear();
                            temp=q.front();
                            c=letter;
                            res.push_back(beginWord);
                            while(temp)
                                res.push_back(temp->word),temp=temp->parent;
                            result.push_back(res);
                        }
                        else if(dict.find(q.front()->word)!=dict.end())
                        {
                            q.push(new node(q.front()->word,q.front()));
                            to_del.push_back(q.front()->word);
                        }
                    }
                    c=letter;
                }
                q.pop();
            }
            for(string &x:to_del)
                dict.erase(x);
            to_del.clear();
            if(done)
                return result;
        }
        return result;
    }
};