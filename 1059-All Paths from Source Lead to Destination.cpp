/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    int dfs(Treclass Solution {
public:
    vector<vector<int>> adjList;
    string color;
    int d;
    bool dfs(int node)
    {
        if(adjList[node].empty())
            return node==d;
        color[node]='G';
        for(int &n:adjList[node])
            if(color[n]=='G'||color[n]=='W'&&!dfs(n))
                return false;
        color[node]='B';
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        color.resize(n,'W');
        d=destination;
        adjList.resize(n);
        for(vector<int> &e:edges)
            adjList[e[0]].push_back(e[1]);
        return dfs(source);
    }
};