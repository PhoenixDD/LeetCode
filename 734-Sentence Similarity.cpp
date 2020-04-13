class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs)
    {
        if(words1.size()!=words2.size())
            return false;
        unordered_map<string,unordered_set<string>> pair;
        for(vector<string> &v:pairs)
            pair[v[0]].insert(v[1]),pair[v[1]].insert(v[0]);
        for(int i=0;i<words1.size();i++)
            if(words2[i]!=words1[i]&&(!pair.count(words2[i])||!pair[words2[i]].count(words1[i])))
                return false;
        return true;
        
    }
};