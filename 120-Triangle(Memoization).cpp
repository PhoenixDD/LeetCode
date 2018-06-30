class Solution {
public:
    vector<vector<int>> memo;
    int minimumTotal(vector<vector<int>>& triangle,int row,int col)
    {
        if(memo[row][col]!=INT_MAX)
            return memo[row][col];
        return memo[row][col]=row==triangle.size()-1?triangle[row][col]:triangle[row][col]+min(minimumTotal(triangle,row+1,col),minimumTotal(triangle,row+1,col+1));
    }
    int minimumTotal(vector<vector<int>>& triangle)
    {
        memo.resize(triangle.size());
        for(int i=0;i<triangle.size();i++)
            memo[i].resize(i+1,INT_MAX);
        return minimumTotal(triangle,0,0);
    }
};