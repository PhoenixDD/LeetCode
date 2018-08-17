class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict,front,back,temp;
        unordered_set<string>::const_iterator it;
        char letter;
        string word;
        dict.reserve(wordList.size());
        for(string &i:wordList)
            dict.insert(i);
        if(dict.find(endWord)==dict.end())
            return 0;
        front.insert(beginWord);
        back.insert(endWord);
        int dist=2;
        while(!front.empty()&&!back.empty())
        {
            temp.clear();
            if(back.size()<front.size())
                front.swap(back);
            for(it=front.begin();it!=front.end();it++)
            {
                word=*it;
                for(int i=0;i<word.length();i++)
                {
                    letter=word[i];
                    for(int j=0;j<26;j++)
                    {
                        word[i]='a'+j;
                        if(back.find(word)!=back.end())
                            return dist;
                        if(dict.find(word)!=dict.end())
                        {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i]=letter;
                }
            }
            temp.swap(front);
            dist++;
        }
        return 0;
    }
};