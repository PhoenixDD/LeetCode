class Solution {
public:
    vector<vector<int>> Edgelist;
    vector<char> visited;
    vector<int> result;
    bool DFS(int &node)
    {
        visited[node]='g';
        for(auto &i:Edgelist[node])
            if(visited[i]=='w'&&!DFS(i))
                return false;
            else if(visited[i]=='g')
                return false;
        visited[node]='b';
        result.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        Edgelist.resize(numCourses);
        visited.resize(numCourses,'w');
        result.reserve(numCourses);
        for(auto &i:prerequisites)
            Edgelist[i.second].push_back(i.first);
        for(int i=0;i<numCourses;i++)
                if(visited[i]=='w'&&!DFS(i))
                    return {};
        reverse(result.begin(),result.end());
        return result;        
    }
};