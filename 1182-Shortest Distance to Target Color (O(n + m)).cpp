//O(queries.length + colors.length)
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) 
    {
        vector<int> result;
        vector<vector<int>> allQueries(colors.size()+1,vector<int>(3));                 //Store all queries
        allQueries.back()={60000,60000,60000};
        for(int i=colors.size()-1;i>=0;i--)                                 //Fill distances from end
        {
            for(int j=0;j<3;j++)
                allQueries[i][j]=allQueries[i+1][j]+1;
            allQueries[i][colors[i]-1]=0;
        }
        for(int i=1;i<colors.size();i++)                                    //Fill distances from begining
            for(int j=0;j<3;j++)
                allQueries[i][j]=min(allQueries[i-1][j]+1,allQueries[i][j]);
        for(vector<int> &v:queries)
            result.push_back(allQueries[v[0]][v[1]-1]>=60000?-1:allQueries[v[0]][v[1]-1]);
        return result;
    }
};