class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adjList;
    int visitedCount=0;
    bool dfs(int node,int prev)
    {
        visited[node]=true;
        visitedCount++;
        for(int &n:adjList[node])
            if(n!=prev)
            {
                if(visited[n])
                    return false;
                else if(!dfs(n,node))
                    return false;
            }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        visited.resize(n,false);
        adjList.resize(n);
        for(vector<int> &v:edges)
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        return dfs(0,-1)&&visitedCount==n;
    }
};