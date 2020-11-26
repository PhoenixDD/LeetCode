static int memo[11][1<<11];
class Solution {
public:
    int dist(vector<int> &worker, vector<int> &bike)
    {
        return abs(worker.front()-bike.front())+abs(worker.back()-bike.back());
    }
    int dp(vector<vector<int>>& workers, vector<vector<int>>& bikes,int i,int bitVector)
    {
        if(i==0)
            return 0;
        if(memo[i][bitVector]!=-1)
            return memo[i][bitVector];
        memo[i][bitVector]=INT_MAX;
        for(int j=0,mask=1;j<bikes.size();j++,mask<<=1)
            if(!(bitVector&mask))
                memo[i][bitVector]=min(memo[i][bitVector],dist(workers[i-1],bikes[j])+dp(workers,bikes,i-1,bitVector|mask));
        return memo[i][bitVector];
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        memset(memo,-1,sizeof memo);
        return dp(workers,bikes,workers.size(),0);
    }
};