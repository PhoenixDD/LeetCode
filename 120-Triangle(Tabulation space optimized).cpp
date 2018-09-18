class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int> memo(triangle.size());
        memo=triangle.back();
        for(int i=triangle.size()-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                memo[j]=triangle[i][j]+min(memo[j+1],memo[j]);
        return memo[0];
    }
};