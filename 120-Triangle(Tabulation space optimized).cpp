class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<int> memo(triangle.back());
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==triangle.size()-1)
                    memo[j]=triangle[i][j];
                else
                    memo[j]=triangle[i][j]+min(memo[j],memo[j+1]);
            }
        }
        return memo[0];
    }
};