class Solution {
public:
    int result=0;
    unordered_map<int,vector<int>> adjList;
    int dfs(int node,int prev)
    {
        int d1=0,d2=0,d;
        for(int &n:adjList[node])
            if(n!=prev)
            {
                d=dfs(n,node);
                if(d>d1)
                    d2=d1,d1=d;
                else if(d>d2)
                    d2=d;
            }
        result=max(result,d1+d2);
        return d1+1;
    }
    int treeDiameter(vector<vector<int>>& edges) 
    {
        for(vector<int> &v:edges)
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        dfs(0,-1);
        return result;
    }
};