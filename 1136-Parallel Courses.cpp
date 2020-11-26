//Kahn's algorithm
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations)
    {
        vector<int> inDegree(N,0);
        vector<vector<int>> adjList(N);
        for(vector<int> &v:relations)
            inDegree[v[1]-1]++,adjList[v[0]-1].push_back(v[1]-1);
        queue<int> q;
        int sem=0;
        for(int i=0;i<N;i++)
            if(!inDegree[i])
                q.push(i);
        while(!q.empty())
        {
            for(int size=q.size();size;size--,q.pop(),N--)
                for(int &i:adjList[q.front()])
                    if(--inDegree[i]==0)
                        q.push(i);
            sem++;
        }
        return N?-1:sem;
    }
};