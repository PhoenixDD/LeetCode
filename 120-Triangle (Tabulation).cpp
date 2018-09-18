class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>> memo(triangle.size(),vector<int>(triangle.size()));
        memo.back()=triangle.back();
        for(int i=triangle.size()-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                memo[i][j]=triangle[i][j]+min(memo[i+1][j+1],memo[i+1][j]);
        return memo[0][0];;
    }
};