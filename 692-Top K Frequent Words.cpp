class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> map;
        for(string &s:words)
            map[s]++;
        vector<set<string>> freq(words.size()+1);
        vector<string> result;
        int count=0;
        for(auto it=map.begin();it!=map.end();it++)
            freq[it->second].insert(it->first);
        for(int i=words.size();i>0;i--)
            for(auto it=freq[i].begin();it!=freq[i].end();it++)
            {
                count++;
                result.push_back(*it);
                if(count==k)
                    return result;
            }         
    }
};