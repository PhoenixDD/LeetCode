class Solution {
public:
    unordered_set<string> dict;
    queue<string> q;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        char letter;
        dict.reserve(wordList.size());
        for(string &i:wordList)
            dict.insert(i);
        for(int i=0;i<beginWord.length();i++)
        {
            letter=beginWord[i];
            for(int j=0;j<26;j++)
            {
                beginWord[i]='a'+j;
                if(dict.find(beginWord)!=dict.end())
                {
                    q.push(beginWord);
                    dict.erase(beginWord);
                }
            }
            beginWord[i]=letter;
        }
        int dist=2;
        int size;
        while(!q.empty())
        {
            size=q.size();
            for(int k=0;k<size;k++)
            {
                if(q.front()==endWord)
                    return dist;
                for(int i=0;i<q.front().length();i++)
                {
                    letter=q.front()[i];
                    for(int j=0;j<26;j++)
                    {
                        q.front()[i]='a'+j;
                        if(dict.find(q.front())!=dict.end())
                        {
                            q.push(q.front());
                            dict.erase(q.front());
                        }
                    }
                    q.front()[i]=letter;
                }
                q.pop();
            }
            dist++;
        }
        return 0;
    }
};