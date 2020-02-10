class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        vector<vector<int>> prefixSum(mat.size()+1,vector<int>(mat[0].size()+1,0));
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                prefixSum[i+1][j+1]=prefixSum[i+1][j]+prefixSum[i][j+1]-prefixSum[i][j]+mat[i][j];
        int startI,startJ,endI,endJ;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
            {
                startI=max(0,i-K),startJ=max(0,j-K),endI=min((int)mat.size()-1,i+K),endJ=min((int)mat[0].size()-1,j+K);
                mat[i][j]=prefixSum[endI+1][endJ+1]-prefixSum[startI][endJ+1]-prefixSum[endI+1][startJ]+prefixSum[startI][startJ];
            }
        return mat;
    }
};