class Solution {
public:
    struct node
    {
        string word;
        node* parent;
        node(string w,node* p=NULL): word(w),parent(p){}
    };
    int num_swaps=0;
    vector<string> temp_res;
    vector<vector<string>> result;
    void sequential(node* start)
    {
        if(start)
        {
            sequential(start->parent);
            temp_res.push_back(start->word);
        }
    }
    void add(node* start,node* end)                                 //oderly print
    {
        temp_res.clear();
        if(num_swaps&1)
        {
            sequential(end);
            while(start)
            {
                temp_res.push_back(start->word);
                start=start->parent;
            }
        }
        else
        {
            sequential(start);
            while(end)
            {
                temp_res.push_back(end->word);
                end=end->parent;
            }
        }
        result.push_back(temp_res);
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict;
        unordered_multimap<string,node*> front,back,temp;
        unordered_multimap<string,node*>::const_iterator it,it2;
        pair<unordered_multimap<string,node*>::const_iterator,unordered_multimap<string,node*>::const_iterator> range;
        bool completed=false;
        char letter;
        string word;
        dict.reserve(wordList.size());
        for(string &i:wordList)
            dict.insert(i);
        if(dict.find(endWord)==dict.end())
            return result;
        front.insert(pair<string,node*>(beginWord,new node(beginWord)));
        back.insert(pair<string,node*>(endWord,new node(endWord)));
        dict.erase(beginWord);
        dict.erase(endWord);
        while(!front.empty()&&!back.empty())
        {
            temp.clear();
            if(back.size()<front.size())
            {
                num_swaps++;                                                            //required for oderly print
                front.swap(back);
            }
            for(it=front.begin();it!=front.end();it++)
            {
                word=it->first;
                for(int i=0;i<word.length();i++)
                {
                    letter=word[i];
                    for(int j=0;j<26;j++)
                    {
                        word[i]='a'+j;
                        if(back.find(word)!=back.end())
                        {
                            completed=true;
                            range=back.equal_range(word);
                            for(it2=range.first;it2!=range.second;it2++)                    //for multiple entries in back
                                add(it->second,it2->second);
                            continue;
                        }
                        if(temp.find(word)!=temp.end()||dict.find(word)!=dict.end())
                        {
                            temp.insert(pair<string,node*>(word,new node(word,it->second)));
                            dict.erase(word);
                        }
                    }
                    word[i]=letter;
                }
            }
            if(completed)
                return result;
            temp.swap(front);
        }
        return result;
    }
};