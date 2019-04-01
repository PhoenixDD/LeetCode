//Same as #373
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        auto func=[&matrix](pair<int,int> &a,pair<int,int> &b){return matrix[a.first][a.second]>matrix[b.first][b.second];};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(func)> pq(func);
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        pair<int,int> temp;
        pq.push({0,0});
        while(--k)
        {
            temp=pq.top();
            pq.pop();
            if(temp.first!=matrix.size()-1&&!visited[temp.first+1][temp.second])
                pq.push({temp.first+1,temp.second}),visited[temp.first+1][temp.second]=true;
            if(temp.second!=matrix[0].size()-1&&!visited[temp.first][temp.second+1])
                pq.push({temp.first,temp.second+1}),visited[temp.first][temp.second+1]=true;
        }
        return matrix[pq.top().first][pq.top().second];
    }
};