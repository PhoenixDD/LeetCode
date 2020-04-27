//O(nk) optimized
class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<vector<int>>& costs,int start,int prev)
    {
        if(!start)
            return 0;
        if(memo[start][prev+1]!=-1)
            return memo[start][prev+1];
        int Min1=INT_MAX,Min2=INT_MAX,minInd1,minInd2;
        for(int i=0;i<costs[0].size();i++)
            if(i!=prev)
            {
                if(costs[start-1][i]<Min1)
                    Min2=Min1,minInd2=minInd1,Min1=costs[start-1][i],minInd1=i;
                else if(costs[start-1][i]<Min2)
                    Min2=costs[start-1][i],minInd2=i;
            }
        memo[start][prev+1]=INT_MAX;
        if(minInd1!=prev&&Min1!=INT_MAX)
            memo[start][prev+1]=costs[start-1][minInd1]+dp(costs,start-1,minInd1);
        if(minInd2!=prev&&Min2!=INT_MAX)
            memo[start][prev+1]=min(memo[start][prev+1],costs[start-1][minInd2]+dp(costs,start-1,minInd2));
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