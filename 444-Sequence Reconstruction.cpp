class Solution {
public:
    vector<vector<int>> adjList;
    vector<char> color;
    bool dfs(vector<int>& org,int i,int node)
    {
        if(i==org.size())
            return true;
        for(int &n:adjList[node])
            if(org[i]==n)
                return dfs(org,i+1,n);
        return false;
    }
    bool hasCycle(int node)
    {
        color[node]='g';
        for(int &i:adjList[node])
            if(color[i]=='g'||color[i]=='w'&&hasCycle(i))
                return true;
        color[node]='b';
        return false;
    }
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs)
    {
        adjList.resize(org.size()+1);
        color.resize(org.size()+1,'w');
        bool start=false;
        for(vector<int> &v:seqs)
        {
            if(!v.empty())
            {
                if(v.front()==org.front())
                    start=true;
                else if(v.front()>org.size())
                    return false;
            }
            for(int j=0;j<(int)v.size()-1;j++)
            {
                if(v[j+1]==org.front())
                    start=true;
                if(v[j+1]>org.size())
                    return false;
                adjList[v[j]].push_back(v[j+1]);
            }
        }
        if(!start)
            return false;
        for(int i=1;i<=org.size();i++)
            if(color[i]=='w'&&hasCycle(i))
                return false;
        return dfs(org,1,org.front());
    }
};