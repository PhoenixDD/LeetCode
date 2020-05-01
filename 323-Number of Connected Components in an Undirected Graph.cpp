class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adjList;
    void dfs(int n)
    {
        visited[n]=true;
        for(int &i:adjList[n])
            if(!visited[i])
                dfs(i);
    }
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        adjList.resize(n);
        visited.resize(n,false);
        int result=0;
        for(vector<int> v:edges)
            adjList[v.front()].push_back(v.back()),adjList[v.back()].push_back(v.front());
        for(int i=0;i<n;i++)
            if(!visited[i])
                result++,dfs(i);
        return result;
    }
};