class Solution {
public:
    vector<int> result;
    unordered_map<int,vector<int>> adjList;
    void dfs(int n)
    {
        result.push_back(n);
        for(int &p:adjList[n])
            dfs(p);
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) 
    {
        
        for(int i=0;i<pid.size();i++)
            adjList[ppid[i]].push_back(pid[i]);
        dfs(kill);
        return result;
    }
};