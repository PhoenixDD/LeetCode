class Solution {
public:
    vector<vector<int>> memo;
    int tryAllPaths(vector<vector<int>>& flights,vector<vector<int>>& days,int city,int weekNo)
    {
        if(weekNo==days[0].size())
            return 0;
        if(memo[city][weekNo]!=-1)
            return memo[city][weekNo];
        memo[city][weekNo]=0;
        for(int &i:flights[city])
            memo[city][weekNo]=max(memo[city][weekNo],days[i][weekNo]+tryAllPaths(flights,days,i,weekNo+1));
        return memo[city][weekNo];
    }
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) 
    {
        memo.resize(days.size(),vector<int>(days[0].size(),-1));
        vector<vector<int>> adjList(flights.size());
        for(int i=0;i<flights.size();i++)
        {
            for(int j=0;j<flights.size();j++)
                if(flights[i][j])
                    adjList[i].push_back(j);
            adjList[i].push_back(i);
        }
        return tryAllPaths(adjList,days,0,0);
    }
};