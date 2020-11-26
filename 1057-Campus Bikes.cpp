typedef pair<int,int> ii;
class Solution {
public:
    int getDist(vector<int> &l,vector<int> &r)
    {
        return abs(l.front()-r.front())+abs(l.back()-r.back());
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes)
    {
        vector<vector<ii>> buckets(2001);
        for(int i=0;i<bikes.size();i++)
            for(int j=0;j<workers.size();j++)
                buckets[getDist(bikes[i],workers[j])].push_back({i,j});
        vector<bool> visited(bikes.size(),false);
        vector<int> result(min(bikes.size(),workers.size()),-1);
        for(int i=0,count=0;i<buckets.size()&&count<bikes.size()&&count<workers.size();i++)
            for(ii &p:buckets[i])
                if(!visited[p.first]&&result[p.second]==-1)
                    result[p.second]=p.first,visited[p.first]=true,count++;
        return result;
    }
};