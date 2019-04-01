//Same as #373
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        auto func=[&matrix](const pair<int,int> &a,const pair<int,int> &b){return matrix[a.first][a.second]<matrix[b.first][b.second];};
        multiset<pair<int,int>,decltype(func)> sorted(func);
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        pair<int,int> temp;
        sorted.insert({0,0});
        while(--k)
        {
            temp=*sorted.begin();
            sorted.erase(sorted.begin());
            if(temp.first!=matrix.size()-1&&!visited[temp.first+1][temp.second])
                sorted.insert({temp.first+1,temp.second}),visited[temp.first+1][temp.second]=true;
            if(temp.second!=matrix[0].size()-1&&!visited[temp.first][temp.second+1])
                sorted.insert({temp.first,temp.second+1}),visited[temp.first][temp.second+1]=true;
        }
        return matrix[sorted.begin()->first][sorted.begin()->second];
    }
};