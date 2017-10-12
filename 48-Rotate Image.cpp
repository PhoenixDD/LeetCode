class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int temp;
        for(int layer=0;layer<matrix.size()/2;layer++)
        {
            for(int i=layer;i<matrix[0].size()-layer-1;i++)
            {
                temp=matrix[layer][i];
                matrix[layer][i]=matrix[matrix.size()-i-1][layer];
                matrix[matrix.size()-i-1][layer]=matrix[matrix.size()-layer-1][matrix[0].size()-i-1];
                matrix[matrix.size()-layer-1][matrix[0].size()-i-1]=matrix[i][matrix[0].size()-layer-1];
                matrix[i][matrix[0].size()-layer-1]=temp;
            }
        }
    }
};