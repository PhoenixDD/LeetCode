class Solution {
public:
    int minJumps(vector<int>& arr)
    {
        std::ios::sync_with_stdio(false);
        unordered_map<int,vector<int>> indices;
        vector<bool> visited(arr.size(),false);
        int steps=0;
        for(int i=0;i<arr.size();i++)
            indices[arr[i]].push_back(i);
        queue<int> q;
        q.push(0),visited[0]=true;
        while(!q.empty())
        {
            for(int size=q.size();size;q.pop(),size--)
            {
                if(q.front()==arr.size()-1)
                    return steps;
                for(int &i:indices[arr[q.front()]])
                    if(!visited[i])
                        q.push(i),visited[i]=true,arr[i]=INT_MIN;
                if(q.front()<arr.size()-1&&!visited[q.front()+1])
                    q.push(q.front()+1),visited[q.front()+1]=true;
                if(q.front()>0&&!visited[q.front()-1])
                    q.push(q.front()-1),visited[q.front()-1]=true;
            }
            steps++;
        }
        return steps;
    }
};