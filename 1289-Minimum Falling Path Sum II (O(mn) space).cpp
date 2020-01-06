class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<vector<int>>& arr,int row,int prev)
    {
        if(row==arr.size())
            return 0;
        if(memo[row][prev]!=-1)
            return memo[row][prev];
        memo[row][prev]=INT_MAX;
        for(int j=0;j<arr[row].size();j++)
            if(j!=prev)
                memo[row][prev]=min(memo[row][prev],arr[row][j]+dp(arr,row+1,j));
        return memo[row][prev];
    }
    int minFallingPathSum(vector<vector<int>>& arr) 
    {
        int Min=INT_MAX;
        memo.resize(arr.size(),vector<int>(arr[0].size(),-1));
        for(int j=0;j<arr[0].size();j++)
            Min=min(Min,arr[0][j]+dp(arr,1,j));
        return Min;
    }
};