//Use smallest 2 numbers from previous row.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) 
    {
        vector<pair<int,int>> minsPrev={{INT_MAX,0},{INT_MAX,0}},minsCurr;
        int temp,Min;
        for(int i=0;i<arr[0].size();i++)
            if(minsPrev[0].first>arr[0][i])
               minsPrev[1]=minsPrev[0],minsPrev[0]={arr[0][i],i};
            else if(minsPrev[1].first>arr[0][i])
                minsPrev[1]={arr[0][i],i};
        for(int i=1;i<arr.size();i++)
        {
            minsCurr={{INT_MAX,0},{INT_MAX,0}};
            for(int j=0;j<arr[i].size();j++)
            {
                Min=INT_MAX;
                for(pair<int,int> &p:minsPrev)
                    if(j!=p.second)
                        Min=min(Min,arr[i][j]+p.first);
                if(Min<minsCurr[0].first)
                    minsCurr[1]=minsCurr[0],minsCurr[0]={Min,j};
                else if(Min<minsCurr[1].first)
                    minsCurr[1]={Min,j};
            }
            minsPrev=minsCurr;
        }
        return min(minsPrev[0].first,minsPrev[1].first);
    }
};