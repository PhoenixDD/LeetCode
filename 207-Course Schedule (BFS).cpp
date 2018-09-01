class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<int> indeg(numCourses);
        vector<vector<int>> Edgelist(numCourses);
        for(auto &i:prerequisites)
            Edgelist[i.first].push_back(i.second),indeg[i.second]++;
        queue<int> q;
        for(int i=0;i<indeg.size();i++)
            if(!indeg[i])
                q.push(i);
        int k=0;
        while(!q.empty())
        {
            k++;
            indeg[q.front()]=-1;
            for(int &i:Edgelist[q.front()])
            {
                if(indeg[i]==-1)
                    return false;
                indeg[i]--;
                if(indeg[i]==0)
                    q.push(i);
            }
            q.pop();
            
        }
        return k==numCourses;
    }
};