//O(nk^2)
class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<vector<int>>& costs,int start,int prev)
    {
        if(!start)
            return 0;
        if(memo[start][prev+1]!=-1)
            return memo[start][prev+1];
        memo[start][prev+1]=INT_MAX;
        for(int i=0;i<costs[0].size();i++)
            if(i!=prev)
                memo[start][prev+1]=min(memo[start][prev+1],costs[start-1][i]+dp(costs,start-1,i));
        return memo[start][prev+1];
    }
    int minCostII(vector<vector<int>>& costs)
    {
        if(costs.empty()||costs[0].empty())
            return 0;
        memo.resize(costs.size()+1,vector<int>(costs[0].size()+1,-1));
        return dp(costs,costs.size(),-1);
        
    }
};