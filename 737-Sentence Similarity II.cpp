class Solution {
public:
    unordered_map<string,int> ids;
    unordered_map<string,vector<string>> adjList;
    void dfs(const string &node,int &id)
    {
        ids[node]=id;
        for(string &s:adjList[node])
            if(!ids.count(s))
                dfs(s,id);
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs)
    {
        if(words1.size()!=words2.size())
            return false;
        for(vector<string> &s:pairs)
            adjList[s[0]].push_back(s[1]),adjList[s[1]].push_back(s[0]);
        int i=0;
        for(auto it=adjList.begin();it!=adjList.end();it++,i++)
            if(!ids.count(it->first))
                dfs(it->first,i);
        for(int i=0;i<words1.size();i++)
            if(words1[i]!=words2[i]&&(!ids.count(words1[i])||ids[words1[i]]!=ids[words2[i]]))
                return false;
        return true;
    }
};