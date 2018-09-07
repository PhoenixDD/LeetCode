class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        if(heightMap.empty())
            return 0;
        auto comp=[](pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){return a.first>b.first;};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(comp)> pq(comp);
        vector<vector<bool>> visited(heightMap.size(),vector<bool>(heightMap[0].size(),false));
        for(int i=0;i<heightMap[0].size();i++)
            pq.push({heightMap[0][i],{0,i}}),visited[0][i]=true;
        for(int i=1;i<heightMap[0].size()-1;i++)
            pq.push({heightMap[heightMap.size()-1][i],{heightMap.size()-1,i}}),visited[heightMap.size()-1][i]=true;
        for(int i=1;i<heightMap.size();i++)
        {
            pq.push({heightMap[i][0],{i,0}}),pq.push({heightMap[i][heightMap[0].size()-1],{i,heightMap[0].size()-1}});
            visited[i][heightMap[0].size()-1]=true,visited[i][0]=true;
        }
        int Max=0,volume=0,i,j;
        pair<int,pair<int,int>> top;
        vector<pair<int,int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty())
        {
            Max=max(pq.top().first,Max);
            top=pq.top();
            pq.pop();
            for(pair<int,int> &dir:dirs)
            {
                i=top.second.first+dir.first,j=top.second.second+dir.second;
                if(i<heightMap.size()&&j<heightMap[0].size()&&!visited[i][j])
                {
                    volume+=max(Max-heightMap[i][j],0);
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        return volume;
    }
};