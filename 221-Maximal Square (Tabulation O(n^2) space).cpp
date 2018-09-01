class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        vector<vector<int>> memo(matrix.size(),vector<int>(matrix[0].size(),0));
        int Max=0;
        for(int i=0;i<matrix.size();i++)
            Max=max(Max,memo[i][0]=matrix[i][0]=='1');
        for(int i=0;i<matrix[0].size();i++)
            Max=max(Max,memo[0][i]=matrix[0][i]=='1');
        for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++)
                if(matrix[i][j]=='1')
                    Max=max(Max,memo[i][j]=1+min({memo[i-1][j-1],memo[i][j-1],memo[i-1][j]}));
        return Max*Max;
    }
};