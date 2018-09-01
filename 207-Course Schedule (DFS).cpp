class Solution {
public:
    vector<char> color;
    vector<vector<int>> Edgelist;
    bool DFS(int &node)
    {
        color[node]='g';
        for(int &j:Edgelist[node])
            if(color[j]=='w'&&!DFS(j))
                return false;
            else if(color[j]=='g')
                return false;
        color[node]='b';
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        color.resize(numCourses,'w');
        Edgelist.resize(numCourses);
        for(auto &i:prerequisites)
            Edgelist[i.first].push_back(i.second);
        for(int i=0;i<Edgelist.size();i++)
        {
            for(int &j:Edgelist[i])
                if(color[j]=='w'&&!DFS(j))
                    return false;
        }
        return true;
    }
};